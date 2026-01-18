class Solution {
public:
    bool checkallcondition(int rowstart , int colstart , int rowend , int colend , vector<vector<int>>& grid){

        int diagonalltr = 0;
        for(int i=rowstart,j=colstart;i<=rowend;i++,j++){
            diagonalltr += grid[i][j];
        }

        int diagonalrtl = 0;
        for(int i=rowstart,j=colend;i<=rowend;i++,j--){
            diagonalrtl += grid[i][j];
        }

        if(diagonalrtl!=diagonalltr) return false;

        for(int i=rowstart;i<=rowend;i++){
            int comparesathi = 0;
            for(int j=colstart;j<=colend;j++){
                comparesathi += grid[i][j];
            }
            if(comparesathi!=diagonalltr) return false;
        }

        for(int j=colstart;j<=colend;j++){
            int colcomparesathi = 0;
            for(int r=rowstart;r<=rowend;r++){
                colcomparesathi += grid[r][j];
            }
            if(colcomparesathi!=diagonalltr) return false;
        }

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        
        int maxis = 0;
        int rowlimit = grid.size();
        int collimit = grid[0].size();

        for(int i=0;i<rowlimit;i++){
            for(int j=0;j<collimit;j++){

                int currentrow = i + maxis;
                int currentcol = j + maxis;

                while(currentrow < rowlimit && currentcol < collimit){

                    int rownext = currentrow;
                    int colnext = currentcol;

                    if(checkallcondition(i,j,rownext,colnext,grid)){
                        maxis = max(maxis, rownext - i);
                    }

                    currentrow++;
                    currentcol++;
                }
            }
        }

        return maxis + 1;
    }
};
