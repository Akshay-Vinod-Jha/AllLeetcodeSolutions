class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int currentpower=1,length=nums.size();
        for(int i=0;i<length;i++){
            if(nums[i]==(k*currentpower)) currentpower++;
            if(nums[i]>(k*currentpower)) return (k*currentpower);
        }
        return (k*currentpower);
    }
};