class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    bool helper(
        int xstart,
        int ystart,
        int xend,
        int yend,
        vector<vector<int>>& grid,
        vector<vector<bool>>& vis,
        int health,
        vector<vector<vector<int>>>& dp
    ) {
        if (xstart == xend && ystart == yend) {
            return health > 0;
        }

        if (health <= 0) return false;

        if(dp[xstart][ystart][health]!=-1) return dp[xstart][ystart][health];

        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int newx = xstart + dx[i];
            int newy = ystart + dy[i];

            if (newx >= 0 && newx < row &&
                newy >= 0 && newy < col &&
                !vis[newx][newy]) {

                vis[newx][newy] = true;

                bool res = helper(
                    newx,
                    newy,
                    xend,
                    yend,
                    grid,
                    vis,
                    grid[newx][newy] == 1 ? health - 1 : health,
                    dp
                );

                if (res) return dp[xstart][ystart][health] = true;

                vis[newx][newy] = false;
            }
        }

        return dp[xstart][ystart][health] = false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {



        int row = grid.size();
        int col = grid[0].size();

        vector<vector<vector<int>>> dp(row,vector<vector<int>>(col,vector<int>(health+1,-1)));

        if (grid[0][0] == 1)
            health--;

        if (health <= 0)
            return false;

        vector<vector<bool>> vis(
            row,
            vector<bool>(col, false)
        );

        vis[0][0] = true;

        return helper(
            0,
            0,
            row - 1,
            col - 1,
            grid,
            vis,
            health,
            dp
        );
    }
};