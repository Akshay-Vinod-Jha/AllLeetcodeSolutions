class Solution {
public:
    void markallvisited( vector<int>& vis, int node , vector<vector<int>>& a ,vector<int>& v){

        for(auto& ind:a[node]){
            if(vis[ind]==0){
                vis[ind]=1;
                v.push_back(ind);
                markallvisited(vis,ind,a,v);
            }
        }

    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector< vector<int> > a(n);

        for(auto& ind:edges){
            
            int first = ind[0];
            int second = ind[1];
            a[first].push_back(second);
            a[second].push_back(first);

        }

        int returnme = 0;
        vector<int> vis(n,0);
        vector<vector<int>> parts;


        for( int i=0;i<n;i++ ){

            if( vis[i]==0 ){
                vector<int> v;
                vis[i]=1;
                v.push_back(i);
                markallvisited(vis,i,a,v);
                parts.push_back(v);
            }

        }

        for(auto& i:parts){

            int size = i.size();
            bool allset = true;
            for(int j=0;j<size;j++){
                for(int k=j+1;k<size;k++){

                   if(find( a[i[j]].begin() , a[i[j]].end() , i[k] )==a[i[j]].end()){
                    allset = false;
                    break;
                   }

                }
                if(!allset) break;
            }
            if(allset) returnme++;

        }

        return returnme;
    }
};