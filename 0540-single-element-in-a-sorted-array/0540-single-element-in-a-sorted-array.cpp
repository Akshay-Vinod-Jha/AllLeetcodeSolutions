class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int retme = 0;
        for(auto& i:nums) retme = retme ^ i;
        return retme;
    }
};