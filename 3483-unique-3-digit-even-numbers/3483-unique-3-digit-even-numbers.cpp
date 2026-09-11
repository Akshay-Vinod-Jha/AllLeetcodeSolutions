class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int retcount = 0;
        vector<int> f(10,0);
        for(auto& i:digits) f[i]++;
    
        for(int hund=1;hund<=9;hund++){
            for(int tens=0;tens<=9;tens++){
                for(int unit=0;unit<=8;unit=unit+2){
                    if(f[hund]==0 || f[tens]==0 || f[unit]==0) continue;
                    else if(
                        (hund==tens && tens==unit && f[hund]<3)   ||
                        (hund==tens && f[hund]<2) ||
                        (hund==unit && f[hund]<2) ||
                        (tens==unit && f[tens]<2)
                    ){
                        continue;
                    }

                    retcount++;
                }
            }
        }
        return retcount;
    }
};