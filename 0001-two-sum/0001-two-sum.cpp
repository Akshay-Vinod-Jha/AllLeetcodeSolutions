class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //as it is asking to return index => we will use hashing wala
        unordered_map<int,int> hashmap;
        int length= nums.size();
        for(int i=0;i<length;i++){
            int remaining = target - nums[i];
            if( hashmap.find(remaining) != hashmap.end() ){
                return {i,hashmap[remaining]};
            }else{
                hashmap[ nums[i] ] = i;
            }
        }
        return {};
    }
};