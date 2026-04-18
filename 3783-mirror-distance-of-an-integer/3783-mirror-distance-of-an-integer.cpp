class Solution {
public:
    int reverse(int n){
        int retme = 0;
        while(n){
            retme = retme*10 + (n%10);
            n = n/10;
        }
        return retme;
    }
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};