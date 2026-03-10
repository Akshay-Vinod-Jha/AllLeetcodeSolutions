class Solution {
public:

    int modme = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int helper(int onel, int zerol, int last1, int limit){

        if(onel == 0 && zerol == 0)
            return 1;

        if(zerol == 0){
            if(last1 == 1) return 0;
            return (onel <= limit) ? 1 : 0;
        }

        if(onel == 0){
            if(last1 == 0) return 0;
            return (zerol <= limit) ? 1 : 0;
        }

        if(dp[onel][zerol][last1] != -1)
            return dp[onel][zerol][last1];

        long long res = 0;

        if(last1 == 0){

            res = (helper(onel-1, zerol, 0, limit) +
                   helper(onel-1, zerol, 1, limit)) % modme;

            if(onel-1 >= limit)
                res = (res - helper(onel-1-limit, zerol, 1, limit) + modme) % modme;

        } else {

            res = (helper(onel, zerol-1, 0, limit) +
                   helper(onel, zerol-1, 1, limit)) % modme;

            if(zerol-1 >= limit)
                res = (res - helper(onel, zerol-1-limit, 0, limit) + modme) % modme;
        }

        return dp[onel][zerol][last1] = res;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        dp.assign(one+1, vector<vector<int>>(zero+1, vector<int>(2, -1)));

        return (helper(one, zero, 0, limit) +
                helper(one, zero, 1, limit)) % modme;
    }
};