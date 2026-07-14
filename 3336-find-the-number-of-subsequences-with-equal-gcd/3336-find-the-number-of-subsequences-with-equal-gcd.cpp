class Solution {
public:

    static const int modme = 1000000007;

    int helper(
        int index,
        int takengcd,
        int nottakengcd,
        vector<int>& nums,
        int maxsize,
        vector<vector<vector<int>>>& dp
    ) {

        if (index == maxsize) {
            if (takengcd != 0 && nottakengcd != 0 && takengcd == nottakengcd)
                return 1;
            return 0;
        }

        if (dp[index][takengcd][nottakengcd] != -1)
            return dp[index][takengcd][nottakengcd];

        long long ans = 0;

        ans = (ans + helper(
                        index + 1,
                        gcd(takengcd, nums[index]),
                        nottakengcd,
                        nums,
                        maxsize,
                        dp)) % modme;

        ans = (ans + helper(
                        index + 1,
                        takengcd,
                        gcd(nottakengcd, nums[index]),
                        nums,
                        maxsize,
                        dp)) % modme;

        ans = (ans + helper(
                        index + 1,
                        takengcd,
                        nottakengcd,
                        nums,
                        maxsize,
                        dp)) % modme;

        return dp[index][takengcd][nottakengcd] = (int)ans;
    }

    int subsequencePairCount(vector<int>& nums) {

        vector<vector<vector<int>>> dp(
            nums.size() + 1,
            vector<vector<int>>(201, vector<int>(201, -1)));

        return helper(0, 0, 0, nums, nums.size(), dp);
    }
};