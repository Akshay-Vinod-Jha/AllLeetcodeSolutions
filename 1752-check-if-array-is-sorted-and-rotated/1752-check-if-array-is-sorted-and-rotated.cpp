class Solution {
public:
    bool check(vector<int>& nums) {
        int index = 0;
        int length = nums.size();bool breakedseries=false;
        for (int i = 0; i < length - 1; i++) {
            if (nums[i] <= nums[i + 1]) {
                index++;
            } else {
                breakedseries=true;
                index++;
                break;
            }
        }
        if(!breakedseries){return !breakedseries;}
        for (int i = 0; i < length - 1; i++) {
            if (nums[(i + index) % length] <= nums[(i + index + 1) % length]) {
            } else {
                return false;
            }
        }
        return true;
    }
};