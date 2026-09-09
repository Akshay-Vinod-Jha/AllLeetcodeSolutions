class Solution {
public:
    long long countCommas(long long n) {
        string s = to_string(n);
        int length = s.length();
        if(length <= 3) return 0;
        long long retme = 0;
        long long starting = 9000;
        for(int i = 4; i < length; i++){
            int upar = i/3;
            int niche = i%3;
            if(niche == 0 && upar > 0){
                retme += (upar-1)*starting;
            }
            else{
                retme += upar*starting;
            }
            starting = starting*10;
        }
        long long base = pow(10, length-1);
        long long bacha = n - base + 1;
        int upar = length/3;
        int niche = length%3;
        if(niche == 0 && upar > 0){
            retme += (upar-1)*bacha;
        }
        else{
            retme += upar*bacha;
        }
        return retme;
    }
};