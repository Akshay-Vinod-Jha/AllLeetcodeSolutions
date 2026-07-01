class Solution {
public:
    int helper(
        int index,
        bool kharida,
        vector<int>& prices,
        int size,
        int total,
        vector<vector<vector<int>>>& dp
    ){

        if(index==size) return 0;

        if(total>=2) return 0;

        if(dp[index][kharida][total]!=-1) return dp[index][kharida][total];

        int retme = 0;
        if(kharida){
            retme = max(
                prices[index] +  helper(index+1,false,prices,size,total+1,dp),
                helper(index+1,true,prices,size,total,dp)
            );
        }else{
            retme = max(
                -prices[index] + helper(index+1,true,prices,size,total,dp),
                helper(index+1,false,prices,size,total,dp)
            );
        }
        return  dp[index][kharida][total] = retme;

    }
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<vector<int>>> dp(size,vector<vector<int>>(2,vector<int>(2,-1)));
        return helper(0,false,prices,prices.size(),0,dp);
    }
};