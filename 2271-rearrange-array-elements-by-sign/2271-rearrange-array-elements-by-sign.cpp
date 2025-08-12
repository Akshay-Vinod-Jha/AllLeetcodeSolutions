class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posindex = 0 , negindex = 1,length = nums.size();
        vector<int> returnme(length,0);
        for(int i=0;i<length;i++){
            if(nums[i] > 0){
                returnme[posindex] = nums[i];
                posindex +=2;
            }else{
                returnme[negindex] = nums[i];
                negindex +=2;
            }
        }
        return returnme;
    }
};