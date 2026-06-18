class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int size = nums.size();

        int sum = 0;
        for(auto &i : nums) sum += i;

        if(target > sum || target < -sum) return 0;

        vector<vector<int>> dp(size + 1,
                               vector<int>(2 * sum + 1, 0));

        dp[0][sum] = 1;

        for(int index = 1; index <= size; index++) {

            for(int currenttarget = -sum;
                currenttarget <= sum;
                currenttarget++) {

                int plus = 0;
                int minus = 0;

                int prevtarget = currenttarget - nums[index - 1];
                if(prevtarget >= -sum && prevtarget <= sum) {
                    plus = dp[index - 1][prevtarget + sum];
                }

                prevtarget = currenttarget + nums[index - 1];
                if(prevtarget >= -sum && prevtarget <= sum) {
                    minus = dp[index - 1][prevtarget + sum];
                }

                dp[index][currenttarget + sum] = plus + minus;
            }
        }

        return dp[size][target + sum];
    }
};