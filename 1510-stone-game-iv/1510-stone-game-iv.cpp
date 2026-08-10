class Solution {
public:
    int helper(int n,vector<bool>& dp,vector<int>& vis){
        if(n==0) return false;

        if(vis[n]!=-1) return dp[n];
            
        for(int i=1;i*i<=n;i++){
            int double_is = i*i;
            if(helper(n-double_is,dp,vis)==false){
                vis[n] = 1;
                return dp[n]=true;
            }
        }

        vis[n]=0;
        return dp[n]=false;
    }
    bool winnerSquareGame(int n) {

        vector<bool> dp(n+1,false);
        vector<int> vis(n+1,-1);

        return helper(n,dp,vis);
    }
};