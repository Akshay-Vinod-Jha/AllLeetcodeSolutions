class Solution {
public:
    int helper(
        int index,
        int target,
        vector<int>& coins,
        vector<vector<int>>& dp
    ){
        if(target==0) return 0;

        if(index==0){
            if(target%coins[0] ==  0){
                return target / coins[0];
            }
            return INT_MAX;
        }

        if(dp[index][target]!=-1) return dp[index][target];

        int cont = INT_MAX;
        if(coins[index]<=target){
            int returned = helper(index,target-coins[index],coins,dp);
            if(returned!=INT_MAX){
                cont = 1 + returned;
            }
        }

        int skip = helper(index-1,target,coins,dp);
        return  dp[index][target] = min(cont,skip);

    }
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<vector<int>> dp(size,vector<int>(amount+1,-1));
        int retme = helper(size-1,amount,coins,dp);
        return retme==INT_MAX?-1:retme;
    }
};