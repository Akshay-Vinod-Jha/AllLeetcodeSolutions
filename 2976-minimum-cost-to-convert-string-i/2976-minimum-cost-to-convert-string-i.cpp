
class Solution {
public:

    vector<int> returnmindis(int index,vector<vector< pair<int,int> > >& adj
        ){
        vector<int> returnme(26,INT_MAX);
        returnme[index]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,index});

        while(!pq.empty()){
            int dis = pq.top().first;
            int currentnode = pq.top().second;
            pq.pop();
            if(dis > returnme[currentnode]) continue;

            for(auto& i:adj[currentnode]){
                int nextnode = i.first;
                int nextweight = i.second;

                if(returnme[currentnode]!=INT_MAX &&
                    returnme[currentnode]+nextweight < returnme[nextnode]){
                    returnme[nextnode] = returnme[currentnode] + nextweight;
                    pq.push({returnme[nextnode],nextnode});
                }
            }

        }
        return returnme;

    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        int size = source.size();
        vector<int> sourceint(size);
        vector<int> targetint(size);
        for(int i=0;i<size;i++){
            sourceint[i] = source[i] - 'a';
            targetint[i] = target[i] - 'a';
        }

        int seccondsize = original.size();
        vector<int> originalint(seccondsize);
        vector<int> changedint(seccondsize);
        for(int i=0;i<seccondsize;i++){
            originalint[i] = original[i] - 'a';
            changedint[i] = changed[i] - 'a';
        }


        vector<vector< pair<int,int> > > adj(26);
        for(int i=0;i<seccondsize;i++){
            adj[originalint[i]].push_back({changedint[i],cost[i]});
        }

        vector<vector<int>> mindis(26,vector<int>(26,INT_MAX));
        vector<int> done(26, 0);
        for(int i=0;i<size;i++){
            if(!done[sourceint[i]]){
                mindis[sourceint[i]] = returnmindis(sourceint[i],adj);
                done[sourceint[i]]=1;
            }
            
        }

        long long returnans = 0;

        for(int i=0;i<size;i++){
            if(sourceint[i]==targetint[i]) continue;
            if(mindis[sourceint[i]][targetint[i]] == INT_MAX) return -1;
            else{
                returnans += mindis[sourceint[i]][targetint[i]];
            }
        }
        return returnans;
    }
};