class Solution {
public:
    TreeNode* returnRightMost(TreeNode* root){
        TreeNode* s = root;
        while(s && s->right) s = s->right;
        return s;
    }

    TreeNode* deleteNode(TreeNode* root){
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        TreeNode* req = returnRightMost(root->left);
        req->right = root->right;
        return root->left;
    }

    TreeNode* traversal(TreeNode* root, int low, int high){
        if(!root) return nullptr;

        root->left = traversal(root->left, low, high);
        root->right = traversal(root->right, low, high);

        if(root->val < low || root->val > high){
            root = deleteNode(root);
        }
        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return traversal(root, low, high);
    }
};
