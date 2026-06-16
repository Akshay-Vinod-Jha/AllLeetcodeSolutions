class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n,-1);
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]) return 0;
        
        dp[0]=1;
        for(int xs=0;xs<m;xs++){
          for(int ys=0;ys<n;ys++){
            if(xs==0 && ys==0) continue;
            int up = 0;
            int uxs = xs-1;
            int uys = ys;
            if(uxs>=0 && uys>=0 && dp[uys]!=-1 && obstacleGrid[uxs][uys]!=1){
              up = dp[uys];
            }

            int right = 0;
            uxs = xs;
            uys = ys - 1;
            if(uxs>=0 && uys>=0 && dp[uys]!=-1 && obstacleGrid[uxs][uys]!=1){
              right = dp[uys];
            }
        

            dp[ys] = up + right;

          }
        }

        return dp[n-1];

    }
};


