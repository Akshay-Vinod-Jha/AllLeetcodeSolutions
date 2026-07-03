class Solution {
public:
    int source = 0;
    int destination ;

    bool helper(int mid, vector<vector<pair<int,int>>>& adj, long long k) {

        vector<long long> finalis(destination + 1, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        //distance node
        pq.push({0, source});
        finalis[source] = 0;

        while (!pq.empty()) {
            pair<long long,int> topis = pq.top();
            pq.pop();

            long long distance = topis.first;
            int node = topis.second;

            if (distance > finalis[node]) continue;
            if (distance > k) continue;
            if (node == destination) return true;

            for (auto& i : adj[node]) {
                int v = i.first;
                int w = i.second;

                if (w < mid) continue;

                long long tw = distance + w;

                if (tw < finalis[v]) {
                    finalis[v] = tw;
                    pq.push({finalis[v], v});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        // adjaceny
        int size = online.size();
        destination = size - 1;

        if (!online[destination] || !online[source])
            return -1;

        vector<vector<pair<int,int>>> vi(size);

        int low = INT_MAX, high = INT_MIN;

        for (auto& i : edges) {
            int u = i[0];
            int v = i[1];
            int w = i[2];

            if (!online[u] || !online[v])
                continue;

            vi[u].push_back({v, w});

            low = min(low, w);
            high = max(high, w);
        }

        if (low == INT_MAX)
            return -1;

        int answer = -1;

        // binary search maximum minimum
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (helper(mid, vi, k)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return answer;
    }
};