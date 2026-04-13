class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int size = nums.size();
        int retme = INT_MAX;
        for(int i=0;i<size;i++){
            if(nums[i]==target) retme = min(retme,abs(i-start));
        }
        return retme;
    }
};