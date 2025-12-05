class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int length=nums.size();
        vector<int> ltor(length,0);
        vector<int> rtol(length,0);
        ltor[0]=nums[0];rtol[length-1]=nums[length-1];
        for(int i=1;i<length;i++) ltor[i]=ltor[i-1]+nums[i];
        for(int i=length-2;i>=0;i--) rtol[i]=rtol[i+1]+nums[i];
        int count=0;
        for(int i=0;i<length-1;i++){
            if(abs(ltor[i]-rtol[i+1])%2==0) count++;
        }
        return count;
    }
};