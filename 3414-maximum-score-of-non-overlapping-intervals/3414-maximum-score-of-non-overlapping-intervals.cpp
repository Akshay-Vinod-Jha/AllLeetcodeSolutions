class Solution {
public:

    struct Data {
        long long score = 0;
        array<int, 4> ids{};
        int cnt = 0;
    };

    vector<vector<Data>> dp;
    vector<vector<bool>> vis;
    vector<int> nxt;

    bool better(Data& a, Data& b) {

        if(a.score != b.score)
            return a.score > b.score;

        for(int i = 0; i < min(a.cnt, b.cnt); i++) {
            if(a.ids[i] != b.ids[i])
                return a.ids[i] < b.ids[i];
        }

        return a.cnt < b.cnt;
    }

    Data solve(
        int i,
        int count,
        vector<vector<int>>& intervals
    ) {

        if(i >= intervals.size() || count == 4)
            return Data();

        if(vis[i][count])
            return dp[i][count];

        vis[i][count] = true;

        Data skip = solve(i + 1, count, intervals);

        Data take = solve(nxt[i], count + 1, intervals);

        take.score += intervals[i][2];

        int id = intervals[i][3];

        int pos = take.cnt;

        while(pos > 0 && take.ids[pos - 1] > id) {
            take.ids[pos] = take.ids[pos - 1];
            pos--;
        }

        take.ids[pos] = id;
        take.cnt++;

        if(better(take, skip))
            return dp[i][count] = take;

        return dp[i][count] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        for(int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {

                 if(a[0] == b[0])
                     return a[1] < b[1];

                 return a[0] < b[0];
             });

        nxt.resize(n);

        for(int i = 0; i < n; i++) {

            int low = i + 1;
            int high = n;

            while(low < high) {

                int mid = low + (high - low) / 2;

                if(intervals[mid][0] > intervals[i][1])
                    high = mid;
                else
                    low = mid + 1;
            }

            nxt[i] = low;
        }

        dp.resize(n, vector<Data>(5));
        vis.resize(n, vector<bool>(5, false));

        Data ans = solve(0, 0, intervals);

        vector<int> retme;

        for(int i = 0; i < ans.cnt; i++)
            retme.push_back(ans.ids[i]);

        return retme;
    }
};