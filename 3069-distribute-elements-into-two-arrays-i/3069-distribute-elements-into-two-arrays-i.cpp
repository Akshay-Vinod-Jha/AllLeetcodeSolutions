class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int size = nums.size();
        if(size<3) return nums;
        vector<int> a1 , a2;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for(int i=2;i<size;i++){
            int a1size = a1.size();
            int a2size = a2.size();
            if(a1[a1size-1]>a2[a2size-1]){
                a1.push_back(nums[i]);
            }else{
                a2.push_back(nums[i]);
            }
        }
        vector<int> retme;
        for(auto& i:a1) retme.push_back(i);
        for(auto& i:a2) retme.push_back(i);
        return retme;
    }
};