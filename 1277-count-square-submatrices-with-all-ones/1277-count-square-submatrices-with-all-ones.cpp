class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector< vector <int> > dp = matrix;

        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){

                if(dp[i][j]==1){

                    dp[i][j]  = min(

                        dp[i-1][j],
                        min(dp[i-1][j-1],
                        dp[i][j-1])

                    ) + 1;

                }

            }
        }

        int retme = 0;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                retme += dp[i][j];
            }
        }

        return retme;

    }
};