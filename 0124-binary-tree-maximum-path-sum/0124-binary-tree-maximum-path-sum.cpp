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

    int maxis = INT_MIN;
	int helper(
		TreeNode* root
	){

		if(root==nullptr) return 0;


		int leftis = helper(root->left);
		int rightis = helper(root->right);


		leftis = max(0,leftis);
		rightis = max(0,rightis);


		int current_value = root->val;
		maxis = max(maxis,leftis+rightis+current_value);


		return current_value + max(leftis,rightis);


	}

    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxis;
    }
};