class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for (int i = 0; i <= row - 3; i++) {
            for (int j = 0; j <= col - 3; j++) {
                vector<bool> seen(10, false);
                bool valid = true;
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        int val = grid[x][y];
                        if (val < 1 || val > 9 || seen[val]) {
                            valid = false;
                            break;
                        }
                        seen[val] = true;
                    }
                }
                if (!valid) continue;
                int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                for (int r = 0; r < 3; r++) {
                    int rowSum = grid[i+r][j] + grid[i+r][j+1] + grid[i+r][j+2];
                    if (rowSum != sum) valid = false;
                }
                for (int c = 0; c < 3; c++) {
                    int colSum = grid[i][j+c] + grid[i+1][j+c] + grid[i+2][j+c];
                    if (colSum != sum) valid = false;
                }
                int d1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                int d2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

                if (d1 != sum || d2 != sum) valid = false;

                if (valid) count++;
            }
        }

        return count;
    }
};
