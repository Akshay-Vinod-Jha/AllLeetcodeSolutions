class Solution {
public:
    int comp;
    vector<int> par, sz;

    int Union(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return 0;

        comp--;
        if(sz[pu] > sz[pv]){
            sz[pu] += sz[pv];
            par[pv] = pu;
        }
        else{
            sz[pv] += sz[pu];
            par[pu] = pv;
        }
        return 1;
    }

    int findParent(int node){
        if(par[node] == node) return node;
        return par[node] = findParent(par[node]);
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        comp = n;
        par.resize(n);
        sz.resize(n,1);

        for(int i=0;i<n;i++){
            par[i] = i;
        }

        vector<vector<int>> mustEdges, optEdges;

        for(auto &it:edges){
            if(it[3] == 1) mustEdges.push_back(it);
            else optEdges.push_back(it);
        }

        int minEdge = INT_MAX;

        for(auto &it:mustEdges){

            int u = it[0];
            int v = it[1];
            int w = it[2];

            minEdge = min(minEdge,w);

            if(!Union(u,v))
                return -1;
        }

        sort(optEdges.begin(),optEdges.end(),[](vector<int>&a,vector<int>&b){
            return a[2] > b[2];
        });

        priority_queue<int,vector<int>,greater<int>> minHeap;

        for(auto &it:optEdges){

            int u = it[0];
            int v = it[1];
            int w = it[2];

            if(Union(u,v)){
                minHeap.push(w);
            }
        }

        while(k-- && !minHeap.empty()){
            int x = minHeap.top();
            minHeap.pop();
            minEdge = min(minEdge,2*x);
        }

        if(comp != 1) return -1;

        if(!minHeap.empty()){
            return min(minEdge,minHeap.top());
        }

        return minEdge;
    }
};