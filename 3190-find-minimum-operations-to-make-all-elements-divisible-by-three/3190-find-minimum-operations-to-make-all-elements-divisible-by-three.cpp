class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int returnme=0;
        for(auto &ind:nums){
            int modresult=ind%3;
            returnme+=min(modresult-0,3-modresult);
        }
        return returnme;
    }
};