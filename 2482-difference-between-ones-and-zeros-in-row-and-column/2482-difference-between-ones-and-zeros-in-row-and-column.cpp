class Solution {
public:
    vector<vector<int>> returnans(vector<vector<int>>& grid){

        int row = grid.size();
        int col = grid[0].size();

        int maxis = max(row,col);

        vector<int> rowone(maxis,0);
        vector<int> colone(maxis,0);

        for(int i=0;i<row;i++){
            
            int count = 0;
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) count++;
            }
            rowone[i]=count;

        }

        for(int i=0;i<col;i++){

            int count = 0;
            for(int j=0;j<row;j++){
                if(grid[j][i]==1) count++;
            }
            colone[i]=count;

        }

        vector<vector<int>> ans = grid;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans[i][j] = rowone[i] + colone[j] - (row-rowone[i]) - (col-colone[j]);
            }
        }

        return ans;
    }
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        return returnans(grid);

    }
};