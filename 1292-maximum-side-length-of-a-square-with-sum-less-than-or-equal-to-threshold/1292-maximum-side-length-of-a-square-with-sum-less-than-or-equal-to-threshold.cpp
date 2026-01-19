class Solution {
public:

    bool dopass(vector<vector<int>>& mat,int rowstart,
        int colstart,int rowend,
        int colend,int threshold
        ){

        int sum = 0;
        for(int i=rowstart;i<=rowend;i++){
            for(int j=colstart;j<=colend;j++){
                sum += mat[i][j];
                if(sum > threshold) return false;
            }
        }
        return true;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int row = mat.size();
        int col = mat[0].size();

        int maxis = 0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){

                int rowindex = i + maxis;
                int colindex = j + maxis;

                while(rowindex < row && colindex < col){

                    if(dopass(mat,i,j,rowindex,colindex,threshold)){
                        maxis = (rowindex - i) + 1;
                        rowindex++;
                        colindex++;
                    }else{
                        break;
                    }
                }
            }
        }

        return maxis;
    }
};
