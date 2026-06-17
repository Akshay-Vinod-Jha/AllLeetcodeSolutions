class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));
        for(int j1=0;j1<cols;j1++){
            for(int j2=0;j2<cols;j2++){
                if(j1!=j2){
                    dp[rows-1][j1][j2] = grid[rows-1][j1] + grid[rows-1][j2];
                }else{
                    dp[rows-1][j1][j2] = grid[rows-1][j1];
                }
                
            }
        }
        for(int i = rows-2;i>=0;i--){
        for(int j1=0;j1<cols;j1++){
            for(int j2=0;j2<cols;j2++){
                int toadd = (j1==j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];
                int maxis = INT_MIN;
                for(int rb1=-1;rb1<=1;rb1++){
                    for(int rb2=-1;rb2<=1;rb2++){
                        int nextj1 = j1 + rb1;
                        int nextj2 = j2 + rb2;
                        if(nextj1>=0 && nextj1<cols && nextj2>=0 && nextj2<cols){
                            maxis = max(maxis,toadd+dp[i+1][nextj1][nextj2]);
                        }
                    }
                }
                dp[i][j1][j2] = maxis;
            }
            }
        }
        return dp[0][0][cols-1];
    }
};