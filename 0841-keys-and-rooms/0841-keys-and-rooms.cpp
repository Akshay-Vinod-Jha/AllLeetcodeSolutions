class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){

            int index = q.front();q.pop();
            for(auto& i:rooms[index]){
                if(vis[i]==0){
                    vis[i]=1;
                    q.push(i);
                }
            }

        } 

        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};