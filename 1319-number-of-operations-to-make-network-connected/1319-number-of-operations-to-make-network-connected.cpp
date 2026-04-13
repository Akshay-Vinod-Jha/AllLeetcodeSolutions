class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {  
        int connectionssize = connections.size();
        if(connectionssize < n-1) return -1;
        vector<int> visited(n,0);
        vector<vector<int>> adjacent(n);
        for(auto& indconnections:connections){
            int first = indconnections[0];
            int second = indconnections[1];
            adjacent[first].push_back(second); 
            adjacent[second].push_back(first);
        }

        int count = 0; 
        for(int i=0;i<n;i++){
            if(visited[i]==1) continue;
            count++; 
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                int currentnode = q.front();
                q.pop();

                for(auto& adjacentare:adjacent[currentnode]){
                    if(visited[adjacentare]==1) continue;
                    visited[adjacentare]=1;
                    q.push(adjacentare);
                }
            }
        }

        return count - 1; 
    }
};