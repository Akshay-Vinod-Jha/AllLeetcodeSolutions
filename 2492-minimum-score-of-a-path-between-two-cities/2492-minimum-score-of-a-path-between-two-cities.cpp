class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector< vector< pair<int,int> > > hehe(n+1);
        for(auto& i:roads){
            hehe[i[0]].push_back({i[1],i[2]});
            hehe[i[1]].push_back({i[0],i[2]});
        }
        vector<bool> vis(n+1,false);
        queue<int> q;
        vis[1]=true;
        // node distance
        q.push(1);
        
        int retme = INT_MAX;

        while(!q.empty()){

            int size = q.size();
            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();
                for(auto& adjare:hehe[node]){
                    int inode = adjare.first;
                    int idis = adjare.second;
                    retme = min(retme,idis);
                    if(!vis[inode]){
                        q.push(inode);
                        vis[inode]=true;
                    }
                }
            }

        }

        return retme;

    }
};