class Solution {
public:
    int helper(int xs,int ys,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        if(xs==0 && ys==0) return 1;
        if(xs<0 || ys<0) return 0;
        
        if(obstacleGrid[xs][ys]==1) return 0;
        if(dp[xs][ys]!=-1) return dp[xs][ys];
        int up = helper(xs-1,ys,obstacleGrid,dp);
        int right = helper(xs,ys-1,obstacleGrid,dp);

        return dp[xs][ys]=up+right;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]) return 0;
        return helper(m-1,n-1,obstacleGrid,dp);
    }
};