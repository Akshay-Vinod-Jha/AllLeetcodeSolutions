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
    void inorder(TreeNode* root,vector<int>& v){
        if(!root) return ;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> returnSorted(vector<int>& a,vector<int>& b){
        vector<int> returnme;
        int ap=0,al=a.size(),bp=0,bl=b.size();
        while(ap<al && bp<bl){
            if(a[ap]<b[bp]) returnme.push_back(a[ap++]);
            else returnme.push_back(b[bp++]);
        }
        while(ap<al) returnme.push_back(a[ap++]);
        while(bp<bl) returnme.push_back(b[bp++]);
        return returnme;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        inorder(root1,a);inorder(root2,b);
        if(!root1 && !root2) return {};
        else if(!root1) return b;
        else if(!root2) return a;
        return returnSorted(a,b);
    }
};