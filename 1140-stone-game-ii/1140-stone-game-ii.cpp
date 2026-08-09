class Solution {
public:
    int helper(
        int i, // change
        int m, // change
        int size,
        vector<int>& suffix,
        vector<vector<int>>& dp
    ){

        if(i==size) return 0;

        if(dp[i][m]!=-1) return dp[i][m];

        int best = 0;

        for(int x=1;x<=2*m && x+i<=size;x++){
            
            int res = helper(x+i,max(m,x),size,suffix,dp);

            int hehe = suffix[i] - res;

            best = max(best,hehe);
            

        }

        return dp[i][m] =  best;


        
    }
    int stoneGameII(vector<int>& piles) {


        int size = piles.size();
        vector<vector<int>> dp(size,vector<int>(2*(size+1),-1));
        vector<int> s(size+1,0);
        for(int i=size-1;i>=0;i--){
            s[i] = piles[i] + s[i+1];
        }

        return helper(0,1,size,s,dp);


    }
};