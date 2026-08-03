class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> vis(rows,vector<bool>(cols,false));

        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};

        int count = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                // 1 chahiye
                if(grid[i][j]=='1' && vis[i][j]==false){

                    count++;

                    queue< pair<int,int> > q;
                    q.push({i,j});
                    vis[i][j] = true;
                    while(!q.empty()){

                        int i_is = q.front().first;
                        int j_is = q.front().second;
                        q.pop();


                        for(int k=0;k<4;k++){

                            int new_i = i_is + dx[k];
                            int new_j = j_is + dy[k];
                            
                            if(new_i>=0 && new_i<rows && new_j>=0 && new_j<cols && vis[new_i][new_j]==false && grid[new_i][new_j]=='1'){
                                vis[new_i][new_j] = true;
                                q.push({new_i,new_j});
                            }


                        }

                    }

                }
            }
        }

        return count;
    }
};