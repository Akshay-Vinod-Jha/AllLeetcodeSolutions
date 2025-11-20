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
class BSTIterator {
public:
    int cindex=-1,limit=-1;
    vector<int> inorder;
    void fillVector(TreeNode* root){
        if(!root) return ;
        fillVector(root->left);
        inorder.push_back(root->val);
        fillVector(root->right);
    }
    BSTIterator(TreeNode* root) {
        fillVector(root);
        cindex=-1;
        limit=inorder.size();
    }
    
    int next() {
        return inorder[++cindex];
    }
    
    bool hasNext() {
        return cindex+1<limit;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */