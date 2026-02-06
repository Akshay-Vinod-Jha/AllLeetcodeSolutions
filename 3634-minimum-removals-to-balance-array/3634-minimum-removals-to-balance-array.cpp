class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        int size = nums.size();
        sort(nums.begin(), nums.end());

        if(size <= 1) return 0;

        long long mindiff = LLONG_MAX;
        int j = 0;

        for(int i = 0; i < size; i++){
            long long elefirst = nums[i];

            while(j < size && nums[j] <= elefirst * (long long)k){
                j++;
            }

            long long startdiff = i;
            long long enddiff = size - (j - 1) - 1;
            mindiff = min(mindiff, startdiff + enddiff);
        }

        return mindiff == LLONG_MAX ? 0 : mindiff;
    }
};
