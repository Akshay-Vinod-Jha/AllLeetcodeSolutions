class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int row = grid.size() , col = grid[0].size();
        vector<vector<int>> retme = grid;
        for(int i=x,endi=x+k-1;i<x+k;i++,endi--){
            for(int j=y;j<y+k;j++){
                retme[i][j] = grid[endi][j];
            }
        }
        return retme;
    }
};