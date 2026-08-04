class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int smallest = nums[0]+1;
        int biggest = nums[nums.size()-1]-1;
        vector<int> retme;
        int index = 1;
        while(smallest<=biggest){
            if(nums[index]==smallest){
                index++;
                smallest++;
            }else{
                retme.push_back(smallest);
                smallest++;    
            }
        }
        return retme;
    }
};