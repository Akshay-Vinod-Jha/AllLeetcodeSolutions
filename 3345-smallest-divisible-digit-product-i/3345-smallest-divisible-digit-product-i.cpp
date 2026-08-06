class Solution {
public:
    bool is_pos(int number,int t){
        long long prodis = 1;
        while(number){
            prodis = prodis* (number%10);
            number = number/10;
        }
        return prodis%t==0;
    }
    int smallestNumber(int n, int t) {
       for(int i=n;i<=100;i++){
            if(is_pos(i,t)) return i;
       } 
       return -1;
    }
};