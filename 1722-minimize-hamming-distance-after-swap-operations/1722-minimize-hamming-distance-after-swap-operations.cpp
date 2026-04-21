class Solution {
public:

    int returnmaxelement(vector<int>& source,int size){
        int retme = INT_MIN;
        for(int i=0;i<size;i++){
            retme = max(retme,source[i]);
        }
        return retme;
    }

    void setparent(vector<int>& parent,int size){
        for(int i=0;i<size;i++){
            parent[i]=i;
        }
    }

    int returnultimateparent(int node,vector<int>& parent){
        if(node==parent[node]) return node;
        return parent[node]=returnultimateparent(parent[node],parent);
    }

    void unionbyrank(int first,int second,vector<int>& rank,vector<int>& parent,vector<int>& source){

        int upf = returnultimateparent(first,parent);   
        int ups = returnultimateparent(second,parent);  

        if(upf==ups) return ;

        int rupf = rank[upf];
        int rups = rank[ups];

        if(rupf==rups){
            parent[ups]=upf;
            rank[upf]++;
        }else if(rupf>rups){
            parent[ups]=upf;
        }else{
            parent[upf]=ups;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        int size = source.size();
        vector<int> parent(size,0);
        vector<int> rank(size,0);

        setparent(parent,size);

        for(auto& i:allowedSwaps){
            int first = i[0];
            int second = i[1];

            int upf = returnultimateparent(first,parent);
            int ups = returnultimateparent(second,parent);

            if(upf==ups) continue;

            unionbyrank(first,second,rank,parent,source); 
        }
        unordered_map<int, vector<int>> groups;

        for(int i=0;i<size;i++){
            int up = returnultimateparent(i,parent);
            groups[up].push_back(i);
        }

        int count = 0;
        for(auto& g:groups){

            unordered_map<int,int> freq;
            for(auto& idx:g.second){
                freq[source[idx]]++;
            }
            for(auto& idx:g.second){
                if(freq[target[idx]] > 0){
                    freq[target[idx]]--;
                }else{
                    count++;
                }
            }
        }

        return count;
    }
};