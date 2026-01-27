class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto& i:edges){
            int u = i[0] , v = i[1] , w = i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        } 

        vector<int> mindis(n,INT_MAX);
        mindis[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});


        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dis > mindis[node]) continue;

            for(auto& i:adj[node]){
                int next = i.first;
                int weight = i.second;

                if( mindis[node] + weight < mindis[next] ){
                    mindis[next] = mindis[node] + weight;
                    pq.push({mindis[next],next});
                }
            }
        }        
        return mindis[n-1]==INT_MAX?-1:mindis[n-1];
    }
};