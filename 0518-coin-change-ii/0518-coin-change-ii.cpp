class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int sum = amount;
        int size = coins.size();
        vector<vector<long long>> dp(size,vector<long long>(sum+1,0));
        for(int i=0;i<size;i++){
            dp[i][0] = 1;
        }
        for(int i=0;i<sum+1;i++){
            dp[0][i] = (i%coins[0]==0)? 1 : 0;
        }
        for(int index=1;index<size;index++){
            for(int target=1;target<sum+1;target++){
                int cont = 0;

                if(coins[index] <= target){
                    cont = dp[index][target-coins[index]];
                }
                int skip = dp[index-1][target];
                dp[index][target] =(long long)cont+(long long)skip;
            }
        }
        return dp[size-1][sum];
    }
};