class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int returnme = 0;

        returnme+= nums[0];
        nums.erase(nums.begin());
        sort(nums.begin(),nums.end());
        returnme+= nums[0] + nums[1];
        return returnme;

    }
};