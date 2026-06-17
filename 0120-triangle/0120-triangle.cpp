class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int noofcolumns = rows;
        vector<int> dp(noofcolumns,-1);
        dp[0] = triangle[0][0];
        for(int currentrow=1;currentrow<rows;currentrow++){
            vector<int> temp(noofcolumns,-1);
            for(int coltaken=0;coltaken<=currentrow;coltaken++){

                int ekpiche = coltaken - 1;
                int upar = coltaken;
                int ekpicheres = INT_MAX;
                if(ekpiche>=0 && ekpiche<currentrow){
                    ekpicheres = min(ekpicheres,triangle[currentrow][coltaken]+dp[ekpiche]);
                }
                int uparres = INT_MAX;
                if(upar>=0 && upar<currentrow){
                    uparres = min(uparres,triangle[currentrow][coltaken]+dp[upar]);
                }

                temp[coltaken] = min(ekpicheres,uparres);
            }
            dp = temp;
        }

        int minis = INT_MAX;
        for(int i=0;i<noofcolumns;i++){
            minis = min(minis,dp[i]);
        }
        return minis;
    }
};