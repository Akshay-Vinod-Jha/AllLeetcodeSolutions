class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        
        int odd = 2;
        int even = 1;

        int oddgcd = odd;
        int evengcd = even;

        while(n--){

            if(n<1) return gcd(oddgcd,evengcd);

            odd += 2;
            even += 2;

            oddgcd += odd;
            evengcd += even;


            cout<< gcd(oddgcd,evengcd);

        }

        return gcd(oddgcd,evengcd);

    }
};