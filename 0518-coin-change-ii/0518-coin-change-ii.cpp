class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int sum = amount;
        int size = coins.size();
        vector<long long> dp(sum+1,0);
        for(int i=0;i<size;i++){
            dp[0] = 1;
        }
        for(int i=0;i<sum+1;i++){
            dp[i] = (i%coins[0]==0)? 1 : 0;
        }
        for(int index=1;index<size;index++){
            vector<long long> temp(sum+1,0);
            temp[0] = 1;
            for(int target=1;target<sum+1;target++){
                int cont = 0;

                if(coins[index] <= target){
                    cont = temp[target-coins[index]];
                }
                int skip = dp[target];
                temp[target] =(long long)cont+(long long)skip;
            }
            dp = temp;
        }
        return dp[sum];
    }
};