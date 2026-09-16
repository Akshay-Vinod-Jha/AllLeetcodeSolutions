class Solution {
public:
    int M = 1e9+7;

    int numberOfSets(int n,int k){
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        for(int j=1;j<=k;j++){
            int sum=0;

            for(int i=n-1;i>=0;i--){
                dp[i][j]=(sum+dp[i+1][j])%M;
                sum=(sum+dp[i][j-1])%M;
            }
        }

        return dp[0][k];
    }
};