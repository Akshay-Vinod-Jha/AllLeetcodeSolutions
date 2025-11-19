/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root,int number){
        if(root==nullptr) return new TreeNode(number);
        if(number < root->val){
            root->left=insertIntoBST(root->left,number);
        }else if(number > root->val){
            root->right = insertIntoBST(root->right,number);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int length=preorder.size();
        if(length==0) return nullptr;
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<length;i++){
            root=insertIntoBST(root,preorder[i]);
        }
        return root;
    }
};