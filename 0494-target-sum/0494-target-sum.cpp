class Solution {
public: 
    int helper(int index,int target,vector<int>& nums){
        if(index==-1){
            return (target==0)?1:0;
        }

        int plus = helper(index-1,target-nums[index],nums);
        int minus = helper(index-1,target+nums[index],nums);

        return plus + minus;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        return helper(size-1,target,nums);
    }
};



