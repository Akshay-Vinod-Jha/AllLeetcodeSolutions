class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //applying kadans algorithm
        int max=INT_MIN,sum=0,length=nums.size();
        for(int i=0;i<length;i++){
            sum += nums[i];
            if(sum > max){
                max = sum;
            }
            if(sum < 0){
                sum=0;
            }
        }
        return max;
    }
};