class Solution {
public:
    int rows;
    int cols;
    int dp[501][501][3];

    int helper(vector<vector<int>>& coins, int starti, int startj, int skips) {
        if(starti == rows-1 && startj == cols-1) {
            if(coins[starti][startj] < 0 && skips > 0) {
                return 0;
            }
            return coins[starti][startj];
        }

        if(starti >= rows || startj >= cols) {
            return INT_MIN;
        }

        if(dp[starti][startj][skips] != INT_MIN) {
            return dp[starti][startj][skips];
        }

        int take = coins[starti][startj] + max(helper(coins, starti+1, startj, skips),
                                               helper(coins, starti, startj+1, skips));

        int skip = INT_MIN;
        if(coins[starti][startj] < 0 && skips > 0) {
            int skipDown = helper(coins, starti+1, startj, skips-1);
            int skipRight = helper(coins, starti, startj+1, skips-1);

            skip = max(skipDown, skipRight);
        }

        return dp[starti][startj][skips] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        rows = coins.size();
        cols = coins[0].size();

        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                for(int k = 0; k < 3; k++) {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }

        return helper(coins, 0, 0, 2);
    }
};