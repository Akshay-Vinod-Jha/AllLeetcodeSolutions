class Solution {
public:
    int helper(
        int index,
        int target,
        vector<int>& coins,
        vector<vector<int>>& dp
    ){
        if(target==0) return 1;

        if(index==0){
            if(target%coins[0] ==  0){
                return 1;
            }
            return 0;
        }

        if(dp[index][target]!=-1) return dp[index][target];

        int cont = 0;
        if(coins[index]<=target){
            cont = helper(index,target-coins[index],coins,dp);
        }

        int skip = helper(index-1,target,coins,dp);
        return  dp[index][target] = cont+skip;

    }
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        int sum = amount;
        vector<vector<int>> dp(size,vector<int>(sum+1,-1));
        int retme = helper(size-1,sum,coins,dp);
        return retme;
    }
};