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
    void recfun(TreeNode* root,int& low,int& high,int& returnme){
        if(!root) return ;
        int c=root->val;
        if(c>=low && c<=high){
            returnme+=c;
            recfun(root->left,low,high,returnme);
            recfun(root->right,low,high,returnme);
        }else if(c<low){
            recfun(root->right,low,high,returnme);
        }else if(c>high){
            recfun(root->left,low,high,returnme);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int returnme=0;
        recfun(root,low,high,returnme);
        return returnme;
    }
};