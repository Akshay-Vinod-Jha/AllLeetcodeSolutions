class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long maxis = 0;
    long long maxsum(TreeNode* root, long long entiresum) {
        if (!root) return 0;
        long long leftsum = maxsum(root->left, entiresum);
        long long rightsum = maxsum(root->right, entiresum);
        long long csum = leftsum + rightsum + root->val;
        long long rem = entiresum - csum;
        long long product = csum * rem;
        maxis = max(maxis, product);
        return csum;
    }
    long long sum(TreeNode* root) {
        if (!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }

    int maxProduct(TreeNode* root) {
        long long entiresum = sum(root);
        maxsum(root, entiresum);
        return maxis % MOD;   
    }
};
