class Solution {
public:
    int helper(
        int w1start,
        int w2start,
        int w1end,
        int w2end,
        string &word1,
        string &word2,
        vector<vector<int>>& dp
    ) {

        if (w2start == w2end)
            return w1end - w1start;

        if (w1start == w1end)
            return w2end - w2start;


        if(dp[w1start][w2start]!=-1) return dp[w1start][w2start];

        if (word1[w1start] == word2[w2start]) {
            return helper(
                w1start + 1,
                w2start + 1,
                w1end,
                w2end,
                word1,
                word2,
                dp
            );
        }

        int fdelete = 1 + helper(
            w1start + 1,
            w2start,
            w1end,
            w2end,
            word1,
            word2,
            dp
        );

        int freplace = 1 + helper(
            w1start + 1,
            w2start + 1,
            w1end,
            w2end,
            word1,
            word2
            ,dp
        );

        int finsert = 1 + helper(
            w1start,
            w2start + 1,
            w1end,
            w2end,
            word1,
            word2,
            dp
        );

        return dp[w1start][w2start] =  min(fdelete, min(freplace, finsert));
    }

    int minDistance(string word1, string word2) {
        int w1size = word1.size();
        int w2size = word2.size();


        vector<vector<int>> dp(w1size,vector<int>(w2size,-1));

        return helper(
            0,
            0,
            w1size,
            w2size,
            word1,
            word2,
            dp
        );
    }
};