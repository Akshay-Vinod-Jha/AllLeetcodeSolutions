class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //applying moore voting algorithm
        int count=0,element=0,length=nums.size();
        for(int i=0;i<length;i++){
            if(count==0){
                count=1;
                element=nums[i];
            }else if(element == nums[i]){
                count++;
            }else {
                count--;
            }
        }
        //wo niche ka nums/2 wala code kyu nahi laga  kyuki alredy mentioned hai hoga matlab hoga , to no chance of getting -1
        return element;
    }
};