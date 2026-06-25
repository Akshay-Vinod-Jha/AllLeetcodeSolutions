class Solution {
public:

    bool helper(
        int sindex,
        int pindex,
        string& s,
        string& p,
        int send,
        int pend,
        vector<vector<int>>& dp
    ){

        if(sindex == send && pindex == pend)
            return true;

        if(pindex == pend)
            return false;

        if(sindex == send){
            while(pindex < pend){
                if(p[pindex] != '*')
                    return false;
                pindex++;
            }
            return true;
        }

        if(dp[sindex][pindex] != -1)
            return dp[sindex][pindex];

        if(p[pindex] == s[sindex]){

            bool retis = helper(
                sindex + 1,
                pindex + 1,
                s,
                p,
                send,
                pend,
                dp
            );

            if(retis)
                return dp[sindex][pindex] = true;
        }
        else if(p[pindex] == '?'){

            bool retis = helper(
                sindex + 1,
                pindex + 1,
                s,
                p,
                send,
                pend,
                dp
            );

            if(retis)
                return dp[sindex][pindex] = true;
        }
        else if(p[pindex] == '*'){

            bool retis = helper(
                sindex + 1,
                pindex,
                s,
                p,
                send,
                pend,
                dp
            );

            if(retis)
                return dp[sindex][pindex] = true;

            retis = helper(
                sindex,
                pindex + 1,
                s,
                p,
                send,
                pend,
                dp
            );

            if(retis)
                return dp[sindex][pindex] = true;
        }

        return dp[sindex][pindex] = false;
    }

    bool isMatch(string s, string p) {

        int send = s.size();
        int pend = p.size();

        vector<vector<int>> dp(
            send + 1,
            vector<int>(pend + 1, -1)
        );

        return helper(
            0,
            0,
            s,
            p,
            send,
            pend,
            dp
        );
    }
};