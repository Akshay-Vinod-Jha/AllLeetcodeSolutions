class Solution {
public:
    int binaryGap(int n) {
        int count = 0;
        int maxis = 1;

        int total = 0;
        while(n){
            int rem = n%2;
            if(rem==0){
                if(total>0) count++;
            }
            else{
                maxis = max(maxis,count);
                count = 1;
                total++;
            }

            n=n/2;
        }
        return total>=2 ? maxis : 0;
    }
};