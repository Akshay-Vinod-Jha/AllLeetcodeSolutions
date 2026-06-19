class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<vector<int>> dp(size,vector<int>(amount+1,INT_MAX));
        for(int i=0;i<size;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<amount+1;i++){
            dp[0][i] = (i%coins[0]==0)? (i/coins[0]) : INT_MAX;
        }
        
        for(int index=1;index<size;index++){
            for(int target=1;target<amount+1;target++){
                int cont = INT_MAX;

                if(coins[index] <= target){
                    int ret = dp[index][target-coins[index]];
                
                    if(ret != INT_MAX){
                        cont = 1 + ret;
                    }
                }
                int skip = dp[index-1][target];
                dp[index][target] = min(cont,skip);
            }
        }
        
        return dp[size-1][amount]==INT_MAX?-1:dp[size-1][amount];
    }
};