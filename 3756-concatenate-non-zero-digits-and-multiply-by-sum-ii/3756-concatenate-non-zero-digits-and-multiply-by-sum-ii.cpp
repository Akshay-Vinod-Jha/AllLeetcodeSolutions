class Solution {
public:
    long long modme = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int sizeis = s.size();

        vector<long long> power(sizeis + 1, 1);
        for (int i = 1; i <= sizeis; i++) {
            power[i] = (power[i - 1] * 10) % modme;
        }

        vector<long long> presum(sizeis + 1, 0);
        for (int i = 1; i <= sizeis; i++) {
            presum[i] = (presum[i - 1] + (s[i - 1] - '0')) % modme;
        }

        vector<long long> premul(sizeis + 1, 0);
        vector<int> lis(sizeis + 1, 0);

        for (int i = 1; i <= sizeis; i++) {
            if (s[i - 1] == '0') {
                premul[i] = premul[i - 1];
                lis[i] = lis[i - 1];
            } else {
                premul[i] = (premul[i - 1] * 10 + (s[i - 1] - '0')) % modme;
                lis[i] = lis[i - 1] + 1;
            }
        }

        vector<int> retme;

        for (auto &q : queries) {
            int first = q[0];
            int second = q[1];

            long long p = power[lis[second + 1] - lis[first]];

            long long mul =
                (premul[second + 1] -
                 (premul[first] * p) % modme +
                 modme) % modme;

            long long sum =
                (presum[second + 1] -
                 presum[first] +
                 modme) % modme;

            retme.push_back((mul * sum) % modme);
        }

        return retme;
    }
};