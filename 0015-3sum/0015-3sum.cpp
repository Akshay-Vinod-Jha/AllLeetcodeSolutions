class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sorting + two pointer
        sort(nums.begin(),nums.end());
        int length = nums.size();
        vector<vector<int>> returnme;
        for(int i = 0; i < length ; i++){
            if( i > 0 && nums[i]==nums[i-1]) continue;
            int j = i + 1;
            int k = length - 1;
            while(j < k){
                long long resultsum = nums[i] + nums[k];
                resultsum += nums[j];
                if( resultsum == 0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    returnme.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[k]==nums[k+1]) k--;
                    while(j<k && nums[j]==nums[j-1]) j--;
                }
                else if( resultsum > 0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return returnme;
    }
};