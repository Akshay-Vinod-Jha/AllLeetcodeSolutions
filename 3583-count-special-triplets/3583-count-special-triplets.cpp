class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1000000007;
        int n = nums.size();
        long long ans = 0;
        unordered_map<int,long long> left, right;
        for (int i = 1; i < n; i++) {
            right[nums[i]]++;
        }
        left[nums[0]]++;
        for (int i = 1; i < n - 1; i++) {
            right[nums[i]]--;
            long long c = nums[i];
            long long want = c * 2;
            if (left.count(want) && right.count(want)) {
                ans = (ans + (left[want] * right[want]) % MOD) % MOD;
            }
            left[nums[i]]++;
        }
        return ans;
    }
};
