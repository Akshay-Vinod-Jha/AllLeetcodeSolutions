class Solution {
public:
    int concatenatedBinary(int n) {
        int modme = 1000000007;
        long long retme = 0;
        int bits = 0;
        for(int i=1;i<=n;i++){
            if((i & (i-1) )== 0) bits++;
            retme = ( (retme<<bits) + i ) % modme;
        }
        return retme;
    }
};