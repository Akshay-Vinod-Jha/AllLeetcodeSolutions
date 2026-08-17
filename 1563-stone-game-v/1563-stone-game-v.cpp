class Solution {
public:

    int helper(
        int start,
        int end,
        vector<int>& stoneValue,
        vector<vector<int>>& dp,
        vector<int>& prefix
    ) {

        if(start == end)
            return 0;

        if(dp[start][end] != -1)
            return dp[start][end];

        int entire_sum = prefix[end + 1] - prefix[start];

        int ans = 0;

        for(int i = start; i < end; i++) {

            int left_part = prefix[i + 1] - prefix[start];
            int right_part = entire_sum - left_part;

            if(left_part < right_part) {

                ans = max(
                    ans,
                    left_part + helper(
                        start,
                        i,
                        stoneValue,
                        dp,
                        prefix
                    )
                );

            }
            else if(left_part > right_part) {

                ans = max(
                    ans,
                    right_part + helper(
                        i + 1,
                        end,
                        stoneValue,
                        dp,
                        prefix
                    )
                );

            }
            else {

                ans = max(
                    ans,
                    max(
                        left_part + helper(
                            start,
                            i,
                            stoneValue,
                            dp,
                            prefix
                        ),

                        right_part + helper(
                            i + 1,
                            end,
                            stoneValue,
                            dp,
                            prefix
                        )
                    )
                );
            }
        }

        return dp[start][end] = ans;
    }


    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(
            n,
            vector<int>(n, -1)
        );

        return helper(
            0,
            n - 1,
            stoneValue,
            dp,
            prefix
        );
    }
};