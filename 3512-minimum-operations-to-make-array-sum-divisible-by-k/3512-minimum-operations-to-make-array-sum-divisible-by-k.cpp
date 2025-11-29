class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(auto& ind:nums) sum+=ind;
        return sum%k;
    }   
};