class Solution {
public:

    bool helper(
        vector<vector<int>>& useme,
        int row,
        int col,
        int constraint,
        vector<int>& dx,
        vector<int>& dy
    ) {

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(row, vector<bool>(col, false));

        if (useme[0][0] < constraint) return false;

        q.push({0, 0});
        vis[0][0] = true;

        while (!q.empty()) {

            pair<int, int> p = q.front();
            q.pop();

            if (p.first == row - 1 && p.second == col - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];

                if (nx >= 0 && nx < row &&
                    ny >= 0 && ny < col &&
                    !vis[nx][ny] &&
                    useme[nx][ny] >= constraint) {

                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        vector<vector<int>> useme(row, vector<int>(col, -1));

        int level = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                pair<int, int> p = q.front();
                q.pop();

                useme[p.first][p.second] = level;

                for (int j = 0; j < 4; j++) {

                    int firstdx = p.first + dx[j];
                    int seconddy = p.second + dy[j];

                    if (firstdx >= 0 && firstdx < row &&
                        seconddy >= 0 && seconddy < col &&
                        !vis[firstdx][seconddy]) {

                        vis[firstdx][seconddy] = true;
                        q.push({firstdx, seconddy});
                    }
                }
            }

            level++;
        }

        int low = 0;
        int high = 400;
        int result = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (helper(useme, row, col, mid, dx, dy)) {
                result = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return result;
    }
};