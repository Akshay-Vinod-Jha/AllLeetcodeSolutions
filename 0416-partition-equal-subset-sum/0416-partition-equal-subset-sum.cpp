class Solution {
public:
    bool helper(
        int index,
        int sum,
        int current,
        vector<int>& nums,
        vector<vector<int>>& dp
    ){

        if(index==-1){
            int rem = sum - current;
            return (rem==current);
        }  

        if(dp[index+1][current]!=-1) return dp[index+1][current];

        int rem = sum - current;
        if(rem==current) return true;

        
 
        bool include = helper(index-1,sum,current+nums[index],nums,dp);
        bool exclude = helper(index-1,sum,current,nums,dp);

        return  dp[index+1][current] = include || exclude;

    }
    bool canPartition(vector<int>& nums) {

        int size = nums.size();
        int sum = 0;
        for(auto& i:nums) sum += i;
        vector<vector<int>> dp(size+2,vector<int>(sum+1,-1));
        return helper(nums.size()-1,sum,0,nums,dp);
    }
};