class Solution {
public:
    int dp[501][501];
    int helper(
        int s1index,
        int s2index,
        string &s1,
        string &s2
    ){

        if(s1index<0 || s2index<0) return 0;
        
        if(dp[s1index][s2index]!=-1) return dp[s1index][s2index];

        if(s1[s1index]==s2[s2index]){
            return 1 + helper(s1index-1,s2index-1,s1,s2);
        }

        return  dp[s1index][s2index] = max(helper(s1index-1,s2index,s1,s2),helper(s1index,s2index-1,s1,s2));

    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        string second = s;
        int size = second.size();
        reverse(second.begin(),second.end());
        int hehe =  helper(size-1,size-1,s,second);
        return size - hehe;
    }
};

