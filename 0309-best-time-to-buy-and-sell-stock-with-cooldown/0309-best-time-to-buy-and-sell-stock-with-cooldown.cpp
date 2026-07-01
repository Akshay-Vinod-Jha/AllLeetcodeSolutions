class Solution {
public:
    int helper(
        int index,
        bool kharida,
        vector<int>& prices,
        int size,
        vector<vector<int>>& dp
    ){

        if(index>=size) return 0;

        int retme = 0;

        if(dp[index][kharida]!=-1) return dp[index][kharida];

        if(kharida){
            // veeka aata
            retme = max(
                prices[index] + helper(index+2,
                0,
                prices,
                size,dp
                ),
                helper(index+1,1,prices,size,dp)
            );

        }else{
            retme = max(
                -prices[index] + helper(index+1,
                1,prices,size,dp
                ),
                helper(index+1,0,prices,size,dp)
            );
        }

        return  dp[index][kharida] = retme;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(0,0,prices,prices.size(),dp);
    }
};