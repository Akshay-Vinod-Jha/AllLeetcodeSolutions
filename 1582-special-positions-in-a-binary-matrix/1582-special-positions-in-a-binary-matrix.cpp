class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int count = 0;
        int row = mat.size();
        int col = mat[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){

                bool rownikla = true;

                for(int k=0;k<col;k++){
                    if(j!=k && mat[i][k]==1){
                        rownikla = false;
                        break;
                    }
                }
                if(!rownikla) continue;

                bool colnikla = true;

                for(int k=0;k<row;k++){
                    if(i!=k && mat[k][j]==1){
                        colnikla = false;
                        break;
                    }
                }
                if(!colnikla) continue;

                if(mat[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};