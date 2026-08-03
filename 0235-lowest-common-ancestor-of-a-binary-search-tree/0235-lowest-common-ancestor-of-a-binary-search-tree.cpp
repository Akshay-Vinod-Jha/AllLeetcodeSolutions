/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
	TreeNode* useme(TreeNode* root, TreeNode* p, TreeNode* q){

		if(root==nullptr) return nullptr;

		if(root->val == p->val || root->val==q->val) return root;


		TreeNode* left_is = useme(root->left,p,q);
		TreeNode* right_is = useme(root->right,p,q);


		if(left_is && right_is) return root;
		else if(left_is) return left_is;
		return right_is;

	}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return useme(root,p,q);
    }
};