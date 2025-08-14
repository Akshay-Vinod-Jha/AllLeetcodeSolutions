class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[row-1].size();
        int top = 0, left = 0, right = col - 1, bottom = row - 1;
        vector<int> temp;

        while (top <= bottom && left <= right) {
            // left -> right
            for (int i = left; i <= right; i++)
                temp.push_back(matrix[top][i]);
            top++;

            // top -> bottom
            for (int i = top; i <= bottom; i++)
                temp.push_back(matrix[i][right]);
            right--;

            // right -> left
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    temp.push_back(matrix[bottom][i]);
                bottom--;
            }

            // bottom -> top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    temp.push_back(matrix[i][left]);
                left++;
            }
        }
        return temp;
    }
};
