class Solution {
public:
    typedef long long ll;

    string buildRemaining(ll need, int slots) {
        string ans;

        for (int d = 9; d >= 2; d--) {
            while (need % d == 0) {
                ans.push_back(d + '0');
                need /= d;
            }
        }

        while (ans.size() < slots) {
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string smallestNumber(string num, long long t) {
        int len = num.size();

        ll check = t;
        for (int p : {2, 3, 5, 7}) {
            while (check % p == 0) {
                check /= p;
            }
        }

        if (check != 1) {
            return "-1";
        }

        vector<ll> rem(len + 1, t);

        for (int idx = 0; idx < len; idx++) {
            int currDigit = num[idx] - '0';

            if (currDigit == 0) {
                break;
            }

            rem[idx + 1] = rem[idx] / gcd(rem[idx], (ll)currDigit);
        }

        if (rem[len] == 1) {
            return num;
        }

        int firstZero = num.find('0');
        int start = len - 1;

        if (firstZero != -1) {
            start = firstZero;
        }

        for (int pos = start; pos >= 0; pos--) {
            ll need = rem[pos];
            int empty = len - pos - 1;

            for (int nxt = (num[pos] - '0') + 1; nxt <= 9; nxt++) {
                ll left = need / gcd(need, (ll)nxt);

                string tail = buildRemaining(left, empty);

                if (tail.size() == empty) {
                    return num.substr(0, pos) + char(nxt + '0') + tail;
                }
            }
        }

        return buildRemaining(t, len + 1);
    }
};