class Solution {
public:
    int returncount(int number){
        int count = 0;
        while(number){
            if(number % 2 == 1) count++;
            number = number / 2;
        }
        return count;
    }   

    bool isprime(int number){

        if(number <= 1) return false;

        for(int i = 2; i * i <= number; i++){
            if(number % i == 0) return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for(int i = left; i <= right; i++){
            if(isprime(returncount(i))) count++;
        }
        return count;
    }
};