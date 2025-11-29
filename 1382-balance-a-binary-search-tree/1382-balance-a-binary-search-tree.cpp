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
    TreeNode* mainLogic(vector<int>& v,int low,int high){
        if(low>high) return nullptr;
        int mid = (low+high)/2;
        TreeNode* r=new TreeNode(v[mid]);
        r->left=mainLogic(v,low,mid-1);
        r->right=mainLogic(v,mid+1,high);
        return r;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;inorder(root,v);
        return mainLogic(v,0,v.size()-1);
    }
};