class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size() , col = matrix[row-1].size();
        int colzero = 1;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    //setting the row as zero
                    matrix[i][0] = 0;
                    if(j==0){
                        colzero=0;
                    }else{
                        matrix[0][j] =0;
                    }
                }
            }
        }
        // andar ka kar liya
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        // ab zero th row 
        for(int j=1;j<col;j++){
            if(matrix[0][0]==0){
                matrix[0][j]=0;
            }
        }
        // ab zero th column
        for(int i=0;i<row;i++){
            if(colzero==0){
                matrix[i][0]=0;
            }
        }
    }
};