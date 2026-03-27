class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        k = k%col;
        vector<vector<int>> dummy = mat;
        for(int i=0;i<row;i++){
            if(i%2==0){
                //left
                for(int j=0;j<col;j++){
                    int current = j - k;
                    if(current<0){
                        current = col + current;
                    }
                    dummy[i][current] = mat[i][j];
                }
            }else{
                //right
                for(int j=0;j<col;j++){
                    int current = j + k;
                    if(current>=col){
                        current = current%col;
                    }
                    dummy[i][current] = mat[i][j];
                }
            }
        }
        return dummy == mat;
    }
};