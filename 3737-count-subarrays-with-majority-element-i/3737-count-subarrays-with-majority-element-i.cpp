class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int length=nums.size();
        int retme=0;
        for(int i=0;i<length;i++){
            unordered_map<int,float> freq;
            for(int j=i;j<length;j++){
                freq[nums[j]]++;
                float currentdist=j-i+1;
                currentdist=(float)currentdist/(float)2;
                if(freq[target]>currentdist) retme++;
            }
        }
        return retme;
    }
};