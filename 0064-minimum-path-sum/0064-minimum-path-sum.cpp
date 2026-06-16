class Solution {
public:
    // int helper(int xs,int ys,vector<vector<int>>& grid,vector<vector<int>> &dp){
    //     if(xs==0 && ys==0) return grid[xs][ys];
    //     if(xs<0 || ys<0) return INT_MAX;

    //     if(dp[xs][ys]!=-1) return dp[xs][ys];

    //     int up =  helper(xs-1,ys,grid,dp);
    //     int down = helper(xs,ys-1,grid,dp);

    //     up = (up==INT_MAX)?INT_MAX:grid[xs][ys]+up;
    //     down = (down==INT_MAX)?INT_MAX:grid[xs][ys]+down;


    //     return  dp[xs][ys]=min(up,down);

    // }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n,-1);
        dp[0] = grid[0][0];
        for(int xs=0;xs<m;xs++){
            for(int ys=0;ys<n;ys++){
                if(xs==0 &&  ys==0) continue;
                int up = INT_MAX;
                int uxs = xs-1;
                int uys = ys;
                if(uxs>=0 && uys>=0 && dp[uys]!=-1){
                    up = grid[xs][ys] + dp[uys];
                }

                uxs = xs;
                uys = ys-1;
                int down = INT_MAX;
                if(uxs>=0 && uys>=0 && dp[uys]!=-1){
                    down = grid[xs][ys] + dp[uys];
                }
                dp[ys] = min(up,down);
            }
        }
        return dp[n-1];

    }
};