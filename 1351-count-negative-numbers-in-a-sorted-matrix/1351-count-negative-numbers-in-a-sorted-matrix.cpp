class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int returnme=0;
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                if(grid[j][i]>=0) continue;
                returnme+=(row-j);break;
            }
        }
        return returnme;
    }
};