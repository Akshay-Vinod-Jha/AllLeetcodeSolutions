class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int count = 0;

        vector<bool> fixed(n - 1, false);

        for (int col = 0; col < m; col++) {
            bool bad = false;

            for (int row = 0; row < n - 1; row++) {
                if (!fixed[row] && strs[row][col] > strs[row + 1][col]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                count++;
                continue; // column removed
            }

            // update fixed relations
            for (int row = 0; row < n - 1; row++) {
                if (!fixed[row] && strs[row][col] < strs[row + 1][col]) {
                    fixed[row] = true;
                }
            }
        }

        return count;
    }
};
