class Solution {
public:
    int numberofbits(int n){
        int count = 0;
        while(n){
            count++;
            n = n/2;
        }
        return count;
    }

    long long returnnumber(int count){
        long long returnme=0;
        for(int i=0;i<count;i++){
            returnme += pow(2,i);
        }
        return returnme;
    }
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        return returnnumber(numberofbits(n)) - n;
    }
};