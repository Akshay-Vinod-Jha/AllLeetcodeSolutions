class Solution {
public:
    void dfs(int currentnode,vector<vector<int>>& adj,vector<bool>& vis){

        vis[currentnode] = true;
        for(auto& i:adj[currentnode]){
            if(vis[i]==false){
                dfs(i,adj,vis);
            }
        }


    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int total = isConnected.size();
        vector<vector<int>> adj(total);
        int rows = isConnected.size();
        int cols = isConnected[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int count = 0;
        vector<bool> vis(total,false);
        for(int i=0;i<total;i++){
            if(vis[i]==false){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};