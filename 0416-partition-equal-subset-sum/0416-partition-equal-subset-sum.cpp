class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int size = nums.size();

        int sum = 0;
        for(auto &i : nums) sum += i;

        if(sum % 2) return false;

        vector<vector<bool>> dp(size + 1,
                                vector<bool>(sum + 1,false));

        dp[0][0] = true;

        for(int index = 1; index <= size; index++){

            for(int current = 0; current <= sum; current++){

                bool exclude = dp[index-1][current];

                bool include = false;

                if(current >= nums[index-1]){
                    include =
                        dp[index-1][current - nums[index-1]];
                }

                dp[index][current] =
                    include || exclude;
            }
        }

        return dp[size][sum/2];
    }
};