class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> m;
        for (int x : nums) m[x]++;

        int ans = 1;

        if (m.count(1)) {
            int cnt = m[1];
            ans = max(ans, (cnt % 2 == 0) ? cnt - 1 : cnt);
        }

        for (auto &[x, cnt] : m) {
            if (x == 1) continue;

            long long num = x;
            int len = 0;

            while (m.count(num) && m[num] >= 2) {
                len += 2;

                if (num > 1000000000LL)
                    break;

                num *= num;
            }

            if (m.count(num))
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};