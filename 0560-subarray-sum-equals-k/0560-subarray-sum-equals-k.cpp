class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //prefixsum , count
        map<int,int> hashmap;
        hashmap[0]=1;
        int prefixsum = 0 , count =0;
        int length = nums.size();
        for(int i=0;i<length;i++){
            prefixsum += nums[i];
            int updatecount = hashmap[ prefixsum - k ];
            count += updatecount;
            hashmap[prefixsum]++;
        }
        return count;
    }
};