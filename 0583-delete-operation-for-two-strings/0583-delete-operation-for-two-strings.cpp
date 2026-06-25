class Solution {
public:

    int dp[501][501];

    int commonHai(
        int s1index,
        int s2index,
        string &s1,
        string &s2
    ){

        if(s1index==0 || s2index==0) return 0;

        if(dp[s1index][s2index]!=-1) return dp[s1index][s2index];

        if(s1[s1index-1]==s2[s2index-1]){
            return dp[s1index][s2index] = 1 + commonHai(s1index-1,s2index-1,s1,s2);
        }

        return dp[s1index][s2index] = max(

            commonHai(s1index-1,s2index,s1,s2),
            commonHai(s1index,s2index-1,s1,s2)

        ); 


    }
    
    int minDistance(string word1, string word2) {
        
        memset(dp,-1,sizeof(dp));
        int s1index = word1.length();
        int s2index = word2.length();

        int comlen = commonHai(s1index,s2index,word1,word2);

        int ans = 0;
        ans += s1index - comlen;
        ans += s2index - comlen;


        return ans;


    }
};