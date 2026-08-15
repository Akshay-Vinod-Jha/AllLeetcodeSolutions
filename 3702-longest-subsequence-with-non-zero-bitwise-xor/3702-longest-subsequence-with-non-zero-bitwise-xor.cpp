class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int count_zero = 0;
        int size = nums.size();
        int total_xor = 0;
        for(auto& i:nums){
            if(i==0) count_zero++;
            total_xor ^= i;
        }

        if(count_zero==size) return 0;
        if(total_xor==0) return size-1;
        return size;

    }
};