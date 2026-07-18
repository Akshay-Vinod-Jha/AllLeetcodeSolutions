class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minis = INT_MAX;
        int maxis = INT_MIN;
        for(auto& i:nums){
            minis = min(minis,i);
            maxis = max(maxis,i);
        }
        return gcd(minis,maxis);
    }
};