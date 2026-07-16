class Solution {
public:
    long long gcdSum(vector<int>& nums) {
    
        int size = nums.size();
        vector<int> a(size,0);
        int maxis = INT_MIN;
        
        for(int i=0;i<size;i++){
            maxis = max(maxis,nums[i]);
            a[i] = gcd(maxis,nums[i]);
        }
        int steps = size / 2;
        sort(a.begin(),a.end());
        long long returnme = 0;
        for(int i=0;i<steps;i++){
            returnme += gcd(a[i],a[size-1-i]);
        }
        return returnme;
        
    }
};