class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long length=prices.size(),count=1;
        if(length<1) return 0;
        long long ln=prices[0];
        long long result=0;
        for(long long i=1;i<length;i++){
            if(ln-prices[i] == 1){
                ln=prices[i];
                count++;
            }else{
                result+=(long long)((long long)count*((long long)count+(long long)1)/(long long)2);
                count=1;
                ln=prices[i];
            }
        }
        result+=(long long)((long long)count*((long long)count+(long long)1)/(long long)2);
        return result;
    }
};