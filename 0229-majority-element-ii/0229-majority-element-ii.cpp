class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0 , ele1 = INT_MIN;
        int count2 = 0 , ele2 = INT_MIN;
        int length = nums.size();
        for(int i = 0 ;i < length ; i++){
            if(count1 == 0 && nums[i]!=ele2){
                count1 = 1;
                ele1 = nums[i];
            }
            else if(count2 == 0 && nums[i]!=ele1){
                count2 = 1;
                ele2 = nums[i];
            }
            else if( nums[i]==ele1 ){
                count1++;
            }
            else if(nums[i]==ele2){
                count2++;
            }
            else{
                count1--;count2--;
            }
        }
        vector<int> result;
        count1 = 0 ,count2 = 0;
        for(int i=0;i<length;i++){
            if(nums[i]==ele1){
                count1++;
            }
            else if(nums[i]==ele2){
                count2++;
            }
        }

        int maxlimit = length/3;
        if(count1 > maxlimit){
            result.push_back(ele1);
        }
        if(count2 > maxlimit){
            result.push_back(ele2);
        }
        sort(result.begin(),result.end());
        return result;
    }
};