class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long dec=0;long long ans=0;
        sort(happiness.begin(),happiness.end());reverse(happiness.begin(),happiness.end());
        for(int i=0;i<k;i++){
            ans+=(happiness[i]-dec)>=0?happiness[i]-dec:0;
            dec++;
        }
        return ans;
    }
};