class Solution {
public:
    int n, m;
    typedef long long ll;
    int mod = 1e9+7;

    vector<vector<pair<ll,ll>>> dp;

    pair<ll,ll> f(int i, int j, vector<vector<int>>& g) {
        
        if(i == n-1 && j == m-1) {
            return {g[i][j], g[i][j]};
        }

        if(dp[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) {
            return dp[i][j];
        }

        ll mx = LLONG_MIN, mn = LLONG_MAX;
        if(i+1 < n) {
            auto [dmax, dmin] = f(i+1, j, g);
            mx = max({mx, g[i][j]*dmax, g[i][j]*dmin});
            mn = min({mn, g[i][j]*dmax, g[i][j]*dmin});
        }
        if(j+1 < m) {
            auto [rmax, rmin] = f(i, j+1, g);
            mx = max({mx, g[i][j]*rmax, g[i][j]*rmin});
            mn = min({mn, g[i][j]*rmax, g[i][j]*rmin});
        }

        return dp[i][j] = {mx, mn};
    }

    int maxProductPath(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();

        dp.assign(n, vector<pair<ll,ll>>(m, {LLONG_MIN, LLONG_MAX}));

        auto [mx, mn] = f(0, 0, g);

        return mx < 0 ? -1 : mx % mod;
    }
};