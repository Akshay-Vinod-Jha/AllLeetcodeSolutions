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
    bool lrootr(TreeNode* root,int k,vector<int>& searchme){
        if(!root) return false;
        int diff=k - root->val;
        if(find(searchme.begin(),searchme.end(),diff)!=searchme.end()) return true;
        searchme.push_back(root->val);
        bool leftside=lrootr(root->left,k,searchme);
        bool rightside=lrootr(root->right,k,searchme);
        return leftside || rightside;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> searchme;
        return lrootr(root,k,searchme);
    }
};