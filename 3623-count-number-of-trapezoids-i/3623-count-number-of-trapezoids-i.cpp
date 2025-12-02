class Solution {
public:
    static const long long MOD = 1000000007;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long,long long> mp;
        for (auto &p : points) mp[p[1]]++;

        vector<long long> v;
        for (auto &e : mp) {
            long long c = e.second;
            if (c >= 2) v.push_back((c * (c - 1) / 2) % MOD);
        }

        long long ans = 0, suffix = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            ans = (ans + v[i] * suffix) % MOD;
            suffix = (suffix + v[i]) % MOD;
        }

        return ans;
    }
};
