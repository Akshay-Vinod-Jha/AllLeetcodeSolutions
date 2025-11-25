class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0) return -1;
        int an=0;
        int countone=0;
        while(true){
            an=((an*10)+1)%k;
            countone++;
            if(an==0) return countone;
        }
        return -1;
    }
};