class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
		int zerocount = 0;
		int retme = 0;
        int size = nums.size();
		while(right<size){
			
			if(nums[right]==0) zerocount++;

			while(zerocount>1){
				if(nums[left]==0) zerocount--;
				left++;
			}

			retme = max(retme,right-left);
			right++;

		}

		return retme;

    }
};