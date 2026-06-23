// class Solution {
// public:
//     long long modme = 1e9 + 7;
//     long long helper(int l,int r,int i,int s,int prev,vector<vector<vector<int>>>& dp){
//         if(i==0) return 1;

//         if(dp[i][prev][s]!=-1) return dp[i][prev][s];

//         int szero = 0;
//         if(s!=0){
//            for(int hehe=prev+1;hehe<=r;hehe++){
//             szero = (szero + helper(l,r,i-1,0,hehe,dp))%modme;
//            }
//         }
//         int sone = 0;
//         if(s!=1){
//             for(int hehe=prev-1;hehe>=l;hehe--){
//                sone = ( sone + helper(l,r,i-1,1,hehe,dp)) % modme;
//             }
//         }

//         return dp[i][prev][s]=(sone+szero)%modme;

//     }
//     int zigZagArrays(int n, int l, int r) {
//         long long retans = 0;
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(r+1,vector<int>(3,-1)));
//         for(int i=l;i<=r;i++){
//             retans = (retans + helper(l,r,n-1,2,i,dp))%modme;
//         }
//         return retans;
//     }
// };


// class Solution {
// public:
//     long long modme = 1e9 + 7;
//     int zigZagArrays(int n, int l, int r) {
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(r+1,vector<int>(3,1)));
//         for(int i=1;i<n;i++){
//             for(int prev=l;prev<=r;prev++){
//                 for(int s=0;s<3;s++){
//                     int szero = 0;
//                     if(s!=0){
//                     for(int hehe=prev+1;hehe<=r;hehe++){
//                         szero = (szero + dp[i-1][hehe][0])%modme;
//                     }
//                     }
//                     int sone = 0;
//                     if(s!=1){
//                         for(int hehe=prev-1;hehe>=l;hehe--){
//                         sone = ( sone + dp[i-1][hehe][1]) % modme;
//                         }
//                     } 
//                     dp[i][prev][s]=(sone+szero)%modme;
//                 }
//             }
//         }
//         int retans = 0;
//         for(int i=l;i<=r;i++){
//             retans =( retans + dp[n-1][i][2])%modme;
//         }
//         return retans;
//     }
// };

class Solution {
public:
    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<array<int,3>> prev(m), curr(m);

        for(int i = 0; i < m; i++) {
            prev[i][0] = 1;
            prev[i][1] = 1;
            prev[i][2] = 1;
        }

        for(int len = 1; len < n; len++) {

            vector<long long> pref0(m + 1, 0);
            vector<long long> pref1(m + 1, 0);

            for(int i = 0; i < m; i++) {
                pref0[i + 1] = (pref0[i] + prev[i][0]) % MOD;
                pref1[i + 1] = (pref1[i] + prev[i][1]) % MOD;
            }

            for(int prevPos = 0; prevPos < m; prevPos++) {

                long long greaterSum =
                    (pref0[m] - pref0[prevPos + 1] + MOD) % MOD;

                long long smallerSum =
                    pref1[prevPos];

                curr[prevPos][0] = smallerSum;
                curr[prevPos][1] = greaterSum;
                curr[prevPos][2] = (greaterSum + smallerSum) % MOD;
            }

            swap(prev, curr);
        }

        long long ans = 0;

        for(int i = 0; i < m; i++) {
            ans = (ans + prev[i][2]) % MOD;
        }

        return (int)ans;
    }
};