class Solution {
public:
    int helper(int currentrow,int crnoofcol,int coltaken,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        
        if(currentrow<0 || crnoofcol<0) return 0;

        if(dp[currentrow][coltaken]!=-1) return dp[currentrow][coltaken];

        int ekpiche = coltaken - 1;
        int upar = coltaken;


        int ekpicheres = INT_MAX;
        if(ekpiche>=0 && ekpiche<crnoofcol){
            int consme = helper(currentrow-1,crnoofcol-1,ekpiche,triangle,dp);
            if(consme!=INT_MAX){
                ekpicheres = min(ekpicheres,triangle[currentrow][ekpiche] + consme);
            }
        }   

        int uparres = INT_MAX;
        if(upar>=0 && upar<crnoofcol){
            int consme = helper(currentrow-1,crnoofcol-1,upar,triangle,dp);
            if(consme!=INT_MAX){
                uparres = min(uparres,triangle[currentrow][upar] + consme);
            }
        }

        return dp[currentrow][coltaken]=min(ekpicheres,uparres);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int noofcolumns = rows;
        int minis = INT_MAX;
        vector<vector<int>> dp(rows,vector<int>(noofcolumns,-1));
        for(int i=0;i<noofcolumns;i++){
            int consme =helper(rows-2,noofcolumns-1,i,triangle,dp);
            if(consme!=INT_MAX){
                
                minis = min(minis, triangle[rows-1][i] + consme) ;

            }
        }
        return minis;
    }
};