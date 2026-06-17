class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            dp[i] = matrix[0][i];
        }
        for(int crow=1;crow<n;crow++){
            vector<int> temp(n,-1);
            for(int ccol=0;ccol<n;ccol++){
                
                int left = ccol - 1;
                int right = ccol + 1;
                int upar = ccol;
                int minis = INT_MAX;
                if(left>=0){
                    minis = min(minis,matrix[crow][ccol] + dp[left]);
                }
                minis = min(minis,matrix[crow][ccol] + dp[upar]);
                if(right<n){
                     minis = min(minis,matrix[crow][ccol] + dp[right]);
                 }

                temp[ccol] = minis;

            }
            dp = temp;
        }   
        int minis = INT_MAX;
        for(int i=0;i<n;i++){
            minis = min(minis,dp[i]);
        } 
        return minis;
    }
};