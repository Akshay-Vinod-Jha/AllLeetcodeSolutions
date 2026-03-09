class Solution {
public:
    int modme = 1e9 + 7;
    int dp[201][201][2];
    int helper(int onel,int zerol,int limit,bool last1){
        if(onel==0 && zerol==0) return 1;

        if(dp[onel][zerol][last1]!=-1) return dp[onel][zerol][last1];

        int res = 0;
        if(last1){
            //0
            for(int i=1;i<=min(zerol,limit);i++){
                res = (res+helper(onel,zerol-i,limit,false))%modme;
            }
        }else{
            //1
            for(int i=1;i<=min(onel,limit);i++){
                res = (res+helper(onel-i,zerol,limit,true))%modme;
            }
        }
        dp[onel][zerol][last1] = res;
        return dp[onel][zerol][last1];
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        return (helper(one,zero,limit,false) + helper(one,zero,limit,true)) % modme;

    }
};