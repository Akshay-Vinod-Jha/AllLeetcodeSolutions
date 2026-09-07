

class Solution {
public:
    int distinctSubseqII(string s) {
        
        int mod = 1e9 + 7;
        vector<long long> dp(26, 0);
        
        long long total = 0;
        
        for(int i = 0; i < s.size(); i++) {
            
            int ch = s[i] - 'a';
            
            long long newSubseq = (total + 1) % mod;
            
            total = (total + newSubseq - dp[ch] + mod) % mod;
            
            dp[ch] = newSubseq;
        }
        
        return total;
    }
};