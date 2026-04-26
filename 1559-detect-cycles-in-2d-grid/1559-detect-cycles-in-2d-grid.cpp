class Solution {
public:

    bool bfs(int i, int j,
        vector<vector<char>>& grid,
        vector<vector<int>>& visited
    ){

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, pair<int,int>>> q;

        // {current, parent}
        q.push({{i,j},{-1,-1}});
        visited[i][j] = 1;

        vector<int> rowadd = {-1,1,0,0};
        vector<int> coladd = {0,0,-1,1};

        while(!q.empty()){

            int x = q.front().first.first;
            int y = q.front().first.second;

            int px = q.front().second.first;
            int py = q.front().second.second;

            q.pop();

            for(int k=0;k<4;k++){

                int newx = x + rowadd[k];
                int newy = y + coladd[k];

                if(newx<0 || newy<0 || newx>=n || newy>=m) continue;

                if(grid[newx][newy] != grid[x][y]) continue;

                // parent ignore
                if(newx==px && newy==py) continue;

                // cycle found
                if(visited[newx][newy]==1) return true;

                visited[newx][newy] = 1;
                q.push({{newx,newy},{x,y}});
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(visited[i][j]==0){
                    if(bfs(i,j,grid,visited)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};