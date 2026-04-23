class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {

        unordered_map<int, vector<int>> iammap;
        int n = nums.size();

        for(int i=0;i<n;i++){
            iammap[nums[i]].push_back(i);
        }

        vector<long long> retme(n,0);

        for(auto& it : iammap){

            vector<int>& pos = it.second;
            int sz = pos.size();

            vector<long long> prefix(sz,0);
            prefix[0] = pos[0];

            for(int i=1;i<sz;i++){
                prefix[i] = prefix[i-1] + pos[i];
            }

            for(int k=0;k<sz;k++){

                long long i = pos[k];

                // left
                long long left_count = k;
                long long left_sum = (k > 0 ? prefix[k-1] : 0);
                long long left = i * left_count - left_sum;

                // right
                long long right_count = sz - k - 1;
                long long right_sum = prefix[sz-1] - prefix[k];
                long long right = right_sum - i * right_count;

                retme[i] = left + right;
            }
        }

        return retme;
    }
};