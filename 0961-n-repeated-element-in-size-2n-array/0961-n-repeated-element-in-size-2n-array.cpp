class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int length=nums.size();length=length/2;
        map<int,int> a;int returnme=0;
        for(auto& i:nums){
            a[i]++;
            if(a[i]>=(length)){
                returnme=i;
                break;
            }
        }
        return returnme;
    }
};