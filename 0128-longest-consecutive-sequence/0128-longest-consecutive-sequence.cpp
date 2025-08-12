class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> iamset(nums.begin(), nums.end());
        int largest = 0;
        for (int num : iamset) {
            if (iamset.find(num - 1) == iamset.end()) {
                int currentNum = num;
                int count = 1;
                while (iamset.find(currentNum + 1) != iamset.end()) {
                    currentNum++;
                    count++;
                }
                largest = max(largest, count);
            }
        }
        return largest;
    }
};
