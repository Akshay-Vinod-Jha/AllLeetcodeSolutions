class Solution {
public:
    int commonHai(
        int s1index,
        int s2index,
        string &s1,
        string &s2,
        vector<vector<int>> &dp
    ){

        if(s1index==0 || s2index==0) return 0;

        if(dp[s1index][s2index]!=-1) return dp[s1index][s2index];

        if(s1[s1index-1]==s2[s2index-1]){
            return dp[s1index][s2index] = 1 + commonHai(s1index-1,s2index-1,s1,s2,dp);
        }

        return dp[s1index][s2index] = max(

            commonHai(s1index-1,s2index,s1,s2,dp),
            commonHai(s1index,s2index-1,s1,s2,dp)

        ); 


    }
    string shortestCommonSupersequence(string str1, string str2) {
        int s1l = str1.length();
        int s2l = str2.length();
        vector<vector<int>> dp(s1l+1,vector<int>(s2l+1,-1));
        commonHai(s1l,s2l,str1,str2,dp);


        string retme = "";

        int i = s1l;
        int j = s2l;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                retme += str1[i-1];
                i--;j--;
            }else{
                if(dp[i][j-1]>dp[i-1][j]){
                    retme += str2[j-1];
                    j--;
                }else{
                    retme += str1[i-1];
                    i--;
                }
            }
        }

        while(i>0){
            retme += str1[i-1];
            i--;
        }

        while(j>0){
            retme += str2[j-1];
            j--;
        }


        reverse(retme.begin(),retme.end());
        return retme;

    }
};