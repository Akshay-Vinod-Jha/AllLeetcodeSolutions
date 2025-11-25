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
    void inorder(TreeNode* root,vector<int>& nodes){
        if(!root) return ;
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }
    void inorderreplace(TreeNode* root,map<int,int>& iammap){
        if(!root) return ;
        inorderreplace(root->left,iammap);
        root->val=iammap[root->val];
        inorderreplace(root->right,iammap);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return root;
        vector<int> nodes;
        inorder(root,nodes);
        sort(nodes.begin(),nodes.end());
        int length=nodes.size();
        map<int,int> maxtillthat;
        maxtillthat[nodes[length-1]]=nodes[length-1];
        for(int i=length-2;i>=0;i--){
            maxtillthat[nodes[i]]=maxtillthat[nodes[i+1]]+nodes[i];
        }
        inorderreplace(root,maxtillthat);
        return root;
    }
};