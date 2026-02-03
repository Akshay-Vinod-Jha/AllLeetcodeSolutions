class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int size = nums.size();
        for (int i = 1; i < size; i++) {
            if (nums[i] == nums[i - 1]) return false;
        }
        int p = -1;
        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i - 1]) continue;
            p = i;
            break;
        }
        if (p == -1) return false;

        int q = -1;
        for (int i = size - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) continue;
            q = i;
            break;
        }
        if (q == -1) return false;

        p--;
        q++;
        if (p <= 0 || q <= p || q >= size - 1) return false;

        for (int i = p + 2; i <= q; i++) {
            if (nums[i] >= nums[i - 1]) return false;
        }

        for (int i = q + 1; i < size; i++) {
            if (nums[i] <= nums[i - 1]) return false;
        }

        return true;
    }
};
