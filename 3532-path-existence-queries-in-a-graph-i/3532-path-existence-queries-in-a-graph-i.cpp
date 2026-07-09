class Solution {
public:

    int findparent(int node,vector<int>& parent){
        if(parent[node]==node){
            return node;
        }

        return parent[node] = findparent(parent[node],parent);
    }

    void unionkaro(int u,int v,vector<int>& bysize,vector<int>& parent){

        int pu = findparent(u,parent);
        int pv = findparent(v,parent);

        int su = bysize[pu];
        int sv = bysize[pv];

        if(pu==pv) return ;

        if(su<sv){
            parent[pu] = pv;
            bysize[pv] += bysize[pu];
        }else{
            parent[pv] = pu;
            bysize[pu] += bysize[pv];
        }

    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int size = nums.size();
        vector<int> bysize(size,1);
        vector<int> parent(size);


        
        for(int i=0;i<size;i++){
            parent[i] = i;
        }

        for(int i=0;i<size-1;i++){

            int uvalue = nums[i];

                
                int vvalue = nums[i+1];

                int absdiff = abs(uvalue-vvalue);

                if(absdiff<=maxDiff){

                    unionkaro(i,i+1,bysize,parent);

                }                

            
        }

        vector<bool> retme;

        for(auto& i:queries){
            if(parent[i[0]]==parent[i[1]]){
                retme.push_back(true);
            }else{
                retme.push_back(false);
            }
        }


    return retme;








    }
};