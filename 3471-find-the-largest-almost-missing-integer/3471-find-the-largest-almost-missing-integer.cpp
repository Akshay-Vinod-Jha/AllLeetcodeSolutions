class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int size = nums.size();
        int return_number = -1;

        if(k == 1) {

            for(int i = 0; i < size; i++) {

                int count = 0;

                for(int j = 0; j < size; j++) {

                    if(nums[i] == nums[j]) {
                        count++;
                    }
                }

                if(count == 1) {
                    return_number = max(return_number, nums[i]);
                }
            }

            return return_number;
        }

        if(k == size) {

            for(int i = 0; i < size; i++) {

                if(nums[i] > return_number) {
                    return_number = nums[i];
                }
            }

            return return_number;
        }

        for(int i = 0; i < size; i++) {

            int min_length = min(i, size-i-1);

            if(min_length == 0) {

                bool found_again = false;

                for(int j = 0; j < size; j++) {

                    if(i != j && nums[i] == nums[j]) {
                        found_again = true;
                        break;
                    }
                }

                if(!found_again && nums[i] > return_number) {
                    return_number = nums[i];
                }
            }
        }

        return return_number;
    }
};