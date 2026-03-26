class Solution {
public:
    typedef long long ll;
    ll tot = 0;

    bool f(vector<vector<int>>& g) {
        int r = g.size();
        int c = g[0].size();

        unordered_set<ll> st;
        ll up = 0;

        for(int i = 0; i <= r-2; i++) {

            for(int j = 0; j < c; j++) {
                st.insert(g[i][j]);
                up += g[i][j];
            }

            ll down = tot - up;
            ll diff = up - down;

            if(diff == 0) return true;

            if(diff == (ll)g[0][0]) return true;
            if(diff == (ll)g[0][c-1]) return true;
            if(diff == (ll)g[i][0]) return true;

            if(i > 0 && c > 1 && st.count(diff)) {
                return true;
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& g) {
        int r = g.size();
        int c = g[0].size();

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                tot += g[i][j];
            }
        }

        if(f(g)) return true;

        reverse(g.begin(), g.end());

        if(f(g)) return true;

        reverse(g.begin(), g.end());

        vector<vector<int>> t(c, vector<int>(r));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                t[j][i] = g[i][j];
            }
        }

        if(f(t)) return true;

        reverse(t.begin(), t.end());

        if(f(t)) return true;

        return false;
    }
};