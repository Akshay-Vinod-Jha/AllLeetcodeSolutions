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
    int heightcalc(TreeNode* proot){
        if(proot==nullptr) return 0;
        return 1 + max(heightcalc(proot->left),heightcalc(proot->right));
    }
    bool firstfun(TreeNode* root){
        if(!root) return true;

        if(!root->left && !root->right){
            return true;
        }   

        int heightofleft = heightcalc(root->left);
        int heightofright = heightcalc(root->right);
        bool isbalanced = false;
        int diff = abs(heightofleft-heightofright);

        if(diff==0 || diff==1){
            isbalanced = true;
        }

        return isbalanced && firstfun(root->left) && firstfun(root->right);
    }
    bool isBalanced(TreeNode* root) {
         return firstfun(root);
    }
};