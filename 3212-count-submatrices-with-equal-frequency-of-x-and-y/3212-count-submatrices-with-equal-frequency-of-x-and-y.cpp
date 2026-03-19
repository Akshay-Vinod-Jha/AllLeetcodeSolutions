class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> prex(row,vector<int>(col,0));
        vector<vector<int>> prey(row,vector<int>(col,0));
        


        int retme = 0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){

                prex[i][j] = (grid[i][j]=='X'?1:0); 
                prey[i][j] = (grid[i][j]=='Y'?1:0); 

                if(i>0){
                    prex[i][j] += prex[i-1][j];
                    prey[i][j] += prey[i-1][j];
                }

                if(j>0){
                    prex[i][j] += prex[i][j-1];
                    prey[i][j] += prey[i][j-1];
                }

                if(i>0 && j>0){
                    prex[i][j] -= prex[i-1][j-1];
                    prey[i][j] -= prey[i-1][j-1];
                }

                if(prex[i][j]==prey[i][j] && prex[i][j]>0){
                    retme++;
                }

            }
        } 
        return retme;
    }
};