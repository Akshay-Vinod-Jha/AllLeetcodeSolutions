class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<long long,long long> m;
        long long valid = 0;
        long long retme = 0;
        long long curretnnum = 0;
        m[0]=1;
        for(auto& i:nums){
            if(target==i){
                valid += m[curretnnum];
                curretnnum++;
            }else{
                curretnnum--;
                valid -= m[curretnnum];
            }
            m[curretnnum]++;
            retme += valid;
        }
        return retme;
    }
};