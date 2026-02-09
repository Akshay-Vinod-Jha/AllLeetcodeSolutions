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
    TreeNode* impfun(int start,int end,vector<int>& converted){
        if(start>end) return nullptr;
        int midis = ( start + end )/2;
        TreeNode* returnme = new TreeNode(converted[midis]);
        returnme->left = impfun(start,midis-1,converted);
        returnme->right = impfun(midis+1,end,converted);
        return returnme;
    }
    void toVector(TreeNode* root,vector<int>& converted){
        if(root==nullptr) return ;
        toVector(root->left,converted);
        converted.push_back(root->val);
        toVector(root->right,converted);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> converted;
        toVector(root,converted);
        int size = converted.size();
        return impfun(0,size-1,converted);

    }
};