class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int crow=1;crow<n;crow++){
            for(int ccol=0;ccol<n;ccol++){
                int left = ccol - 1;
                int right = ccol + 1;
                int upar = ccol;
                int minis = INT_MAX;
                if(left>=0){
                    minis = min(minis,matrix[crow][ccol] + dp[crow-1][left]);
                }
                minis = min(minis,matrix[crow][ccol] + dp[crow-1][upar]);
                if(right<n){
                     minis = min(minis,matrix[crow][ccol] + dp[crow-1][right]);
                 }

                dp[crow][ccol] = minis;

            }
        }   
        int minis = INT_MAX;
        for(int i=0;i<n;i++){
            minis = min(minis,dp[n-1][i]);
        } 
        return minis;
    }
};