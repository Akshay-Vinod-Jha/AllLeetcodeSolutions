class Solution {
public:
    int helper(int xs,int ys,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(xs==0 && ys==0) return grid[xs][ys];
        if(xs<0 || ys<0) return INT_MAX;

        if(dp[xs][ys]!=-1) return dp[xs][ys];

        int up =  helper(xs-1,ys,grid,dp);
        int down = helper(xs,ys-1,grid,dp);

        up = (up==INT_MAX)?INT_MAX:grid[xs][ys]+up;
        down = (down==INT_MAX)?INT_MAX:grid[xs][ys]+down;


        return  dp[xs][ys]=min(up,down);

    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,grid,dp);

    }
};