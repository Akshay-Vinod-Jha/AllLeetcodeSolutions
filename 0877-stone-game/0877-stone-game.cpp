class Solution {
public:
    int helper(int left, int right, vector<int>& piles,
               vector<vector<int>>& dp) {

        if (left == right)
            return piles[left];

        if (dp[left][right] != -1)
            return dp[left][right];

        int takeLeft = piles[left] - helper(left + 1, right, piles, dp);
        int takeRight = piles[right] - helper(left, right - 1, piles, dp);

        return dp[left][right] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helper(0, n - 1, piles, dp) > 0;
    }
};