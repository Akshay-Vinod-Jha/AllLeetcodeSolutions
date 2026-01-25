class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int minis = INT_MAX;
        int left = 0 , size = nums.size();
        while( left+k-1 < size ){
            minis = min(minis, nums[left+k-1] - nums[left] );
            left++;
        }
        return minis == INT_MAX ? 0 : minis ;
    }
};