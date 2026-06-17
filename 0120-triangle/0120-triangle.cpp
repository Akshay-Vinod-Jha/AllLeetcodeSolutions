class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int noofcolumns = rows;
        vector<vector<int>> dp(rows,vector<int>(noofcolumns,-1));
        dp[0][0] = triangle[0][0];
        for(int currentrow=1;currentrow<rows;currentrow++){
            for(int coltaken=0;coltaken<=currentrow;coltaken++){
                int ekpiche = coltaken - 1;
                int upar = coltaken;
                int ekpicheres = INT_MAX;
                if(ekpiche>=0 && ekpiche<currentrow){
                    ekpicheres = min(ekpicheres,triangle[currentrow][coltaken]+dp[currentrow-1][ekpiche]);
                }
                int uparres = INT_MAX;
                if(upar>=0 && upar<currentrow){
                    uparres = min(uparres,triangle[currentrow][coltaken]+dp[currentrow-1][upar]);
                }

                dp[currentrow][coltaken] = min(ekpicheres,uparres);
            }
        }

        int minis = INT_MAX;
        for(int i=0;i<noofcolumns;i++){
            minis = min(minis,dp[rows-1][i]);
        }
        return minis;
    }
};