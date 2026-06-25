class Solution {
public:
    long long helper(
        int sind,
        int tind,
        string& s,
        string& t,
        int send,
        int tend,
        vector<vector<long long>>& dp
    ) {
        if (tind == tend) return 1;
        if (sind == send) return 0;

        if (dp[sind][tind] != -1)
            return dp[sind][tind];

        long long retme = helper(
            sind + 1,
            tind,
            s,
            t,
            send,
            tend,
            dp
        );

        if (s[sind] == t[tind]) {
            retme += helper(
                sind + 1,
                tind + 1,
                s,
                t,
                send,
                tend,
                dp
            );
        }

        return dp[sind][tind] = retme;
    }

    int numDistinct(string s, string t) {
        int ssize = s.size();
        int tsize = t.size();

        if (tsize == 0) return 1;
        if (ssize == 0) return 0;
        if (tsize > ssize) return 0;

        vector<vector<long long>> dp(
            ssize,
            vector<long long>(tsize, -1)
        );

        return helper(
            0,
            0,
            s,
            t,
            ssize,
            tsize,
            dp
        );
    }
};