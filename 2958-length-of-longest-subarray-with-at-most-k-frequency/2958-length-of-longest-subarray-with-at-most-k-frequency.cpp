class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, ans = 0;
        unordered_map<int,int> mp;

        for(int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;

            while(mp[nums[r]] > k) {
                mp[nums[l]]--;
                l++;
            }

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};