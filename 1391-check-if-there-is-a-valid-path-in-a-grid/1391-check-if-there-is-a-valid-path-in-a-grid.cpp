class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<pair<int,int>>> dir(7);
        dir[1] = {{0,-1},{0,1}};
        dir[2] = {{-1,0},{1,0}};
        dir[3] = {{0,-1},{1,0}};
        dir[4] = {{0,1},{1,0}};
        dir[5] = {{0,-1},{-1,0}};
        dir[5] = {{0,-1},{-1,0}};
        dir[6] = {{0,1},{-1,0}}; 

        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=1;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x==n-1 && y==m-1) return true;


            for(auto [dr,dc] : dir[grid[x][y]]){
                int nx = x + dr;
                int ny = y + dc;
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    for(auto [bdr,bdc] : dir[grid[nx][ny]]){
                        if(nx+bdr==x && ny+bdc==y && vis[nx][ny]==0){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return false;
    }
};