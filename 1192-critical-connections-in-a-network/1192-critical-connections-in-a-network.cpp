class Solution {
public:
    
    void dfs(int node,
      vector<int>& discover,
      vector<int>& low,
      vector<int>& parent,
      vector<int>& visited,
      vector<vector<int>>& retme,
      int& timer,
      int passedparent,
      vector<vector<int>>& adj  
      ){

      visited[node]=1;
      discover[node]=timer;
      low[node]=timer;
      parent[node]=passedparent;
      timer++;

      for(auto& adjacentare:adj[node]){

        if(visited[adjacentare]==1){

          if(adjacentare != parent[node]){
            low[node] = min(low[node], discover[adjacentare]);
          }

        }else{

          dfs(adjacentare,
              discover,
              low,
              parent,
              visited,
              retme,
              timer,
              node,
              adj
          );

          low[node] = min(low[node], low[adjacentare]);

          if(low[adjacentare] > discover[node]){
            vector<int> addme;
            addme.push_back(node);
            addme.push_back(adjacentare);
            retme.push_back(addme);
          }
        }
      }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        for(auto& i:connections){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> discover(n,-1);
        vector<int> low(n,-1);
        vector<int> parent(n,-1);
        int timer = 0;
        vector<int> visited(n,0);
        vector<vector<int>> retme;

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(i, discover, low, parent, visited, retme, timer, -1, adj);
            }
        }

        return retme;
    }
};