class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<int> dp(amount+1,INT_MAX);
        for(int i=0;i<size;i++){
            dp[0] = 0;
        }
        for(int i=0;i<amount+1;i++){
            dp[i] = (i%coins[0]==0)? (i/coins[0]) : INT_MAX;
        }
        
        for(int index=1;index<size;index++){
            dp[0] = 0;
            for(int target=1;target<amount+1;target++){
                int cont = INT_MAX;

                if(coins[index] <= target){
                    int ret = dp[target-coins[index]];
                
                    if(ret != INT_MAX){
                        cont = 1 + ret;
                    }
                }
                int skip = dp[target];
                dp[target] = min(cont,skip);
            }
        }
        
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};