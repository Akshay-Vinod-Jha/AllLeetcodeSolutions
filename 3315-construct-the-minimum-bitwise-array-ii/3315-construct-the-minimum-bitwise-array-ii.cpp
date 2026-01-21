class Solution {
public:
    int number_of_bits(int n){
        return (n==0)?1:32-__builtin_clz(n);
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int> returnans;
        for(auto&i:nums){
            if(i%2==0){

                returnans.push_back(-1);
                continue;
            }
            int numberofbits = number_of_bits(i);
            for(int k=numberofbits-1;k>=0;k--){

                int x = i & ~(1<<k);
                if( (x | (x+1)) == i ){
                    returnans.push_back(x);
                    break;
                }
            }
        }
        return returnans;
    }
};