class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int retme = INT_MAX;
        int size = nums.size();
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                for(int k=j+1;k<size;k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k]){
                        int temp = abs(i-j) + abs(j-k) + abs(k-i);
                        retme = min(retme,temp);
                    }
                }
            }
        }
        return retme == INT_MAX ? -1 : retme;
    }
};