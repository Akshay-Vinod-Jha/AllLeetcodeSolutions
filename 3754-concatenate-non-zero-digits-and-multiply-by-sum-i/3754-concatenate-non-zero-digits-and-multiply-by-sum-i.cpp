class Solution {
public:
    long long sumAndMultiply(int n) {
        
        int retme = 0;
        int mul = 1;
        int addme = 0;
        while(n){
            int rem = n%10;
            if(rem!=0){
                retme = rem*mul + retme;
                mul = mul*10;
                addme += rem;
            }
            n = n/10;
        }
        return (long long)retme*(long long)addme;

    }
};