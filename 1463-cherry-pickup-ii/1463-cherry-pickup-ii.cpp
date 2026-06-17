class Solution {
public:
    int helper(int i,int j1,int j2,vector<vector<int>>& grid,int rows,int cols,vector<vector<vector<int>>>& dp){
        if(j1<0 || j1>=cols || j2<0 || j2>=cols) return INT_MIN;

        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

        if(i==rows-1){
            if(j1==j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }



        int toadd = (j1==j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];

        int maxis = INT_MIN;
        for(int rb1=-1;rb1<=1;rb1++){
            for(int rb2=-1;rb2<=1;rb2++){
                int ret = helper(i+1,j1+rb1,j2+rb2,grid,rows,cols,dp);
                if(ret!=INT_MIN){
                    maxis = max(maxis,toadd+ret);
                }
            }
        }

        return dp[i][j1][j2]=maxis;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));
        return helper(0,0,cols-1,grid,rows,cols,dp);
    }
};