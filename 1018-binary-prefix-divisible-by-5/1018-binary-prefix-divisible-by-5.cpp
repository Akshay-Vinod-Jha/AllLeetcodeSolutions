class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long c=0;
        vector<bool> returnme;
        for(auto &ind:nums){
            c=c*2+ind;
            c=c%5;
            returnme.push_back(c%5==0);
        }
        return returnme;
    }
};