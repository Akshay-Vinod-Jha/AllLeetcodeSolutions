class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> copy = mat;

        if(copy == target) return true;

        for(int i = 0; i < 3; i++){

            for(int j = 0; j < row; j++){
                for(int k = 0; k < col; k++){
                    copy[j][k] = mat[row - k - 1][j];
                }
            }

            if(copy == target) return true;

            mat = copy;
        }

        return false;
    }
};