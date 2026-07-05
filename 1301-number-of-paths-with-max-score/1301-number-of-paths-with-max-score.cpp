class Solution {
public:
    int modme = 1e9 + 7;
    pair<int,int>  helper(
        int startx,
        int starty,
        vector<string>& board,
        vector<int>& dx,
        vector<int>& dy,
        vector<vector<pair<int,int>>>& dp,
        vector<vector<int>>& vis
    ){

        if(startx==0 && starty==0){
            return {0,1};
        }

        if(vis[startx][starty]) return dp[startx][starty];

        int maxis = INT_MIN;
        int ways = 0;
        vis[startx][starty] = true;

        for(int i=0;i<=2;i++){

            int newx = startx + dx[i];
            int newy = starty + dy[i];
            
            if(newx>=0 && newy>=0 && board[newx][newy]!='X'){
                //safe

                pair<int,int> helperans = helper(newx,newy,board,dx,dy,dp,vis);
                int pathsum = helperans.first;
                int pathways = helperans.second;
                if(pathsum==INT_MIN) continue;

                int valtoadd = 0;
                if(board[newx][newy]!='E' && board[newx][newy]!='S'){
                    valtoadd = board[newx][newy]-'0';
                }


                int finalis = valtoadd + pathsum;
                if(finalis>maxis){
                    maxis = finalis;
                    ways = pathways;
                }else if(finalis==maxis){
                    ways = (ways+pathways)%modme;
                }
               
            }

        }
        
        if(maxis == INT_MIN){
            return dp[startx][starty] =
                {INT_MIN, 0};
        }

        return dp[startx][starty] = {maxis,ways};

    }
    vector<int> pathsWithMaxScore(vector<string>& board) {



        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<pair<int,int>>> dp(rows,vector<pair<int,int>>(cols,{-1,-1}));
        vector<vector<int>> vis(rows,vector<int>(cols,false));

        vector<int> dx = {0,-1,-1};
        vector<int> dy = {-1,-1,0};
        int hehe = helper(rows-1,cols-1,board,dx,dy,dp,vis).first;
        return {hehe==INT_MIN?0:hehe,helper(rows-1,cols-1,board,dx,dy,dp,vis).second};

    }
};