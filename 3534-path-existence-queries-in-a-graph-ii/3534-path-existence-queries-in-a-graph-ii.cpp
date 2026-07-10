class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& a, int k, vector<vector<int>>& q) {

        vector<pair<int,int>> v;

        for(int i=0;i<n;i++)
            v.push_back({a[i],i});

        sort(v.begin(),v.end());

        vector<int> pos(n);

        for(int i=0;i<n;i++)
            pos[v[i].second]=i;

        vector<vector<int>> up(n,vector<int>(18));

        int r=0;

        for(int l=0;l<n;l++){

            r=max(r,l);

            while(r+1<n &&
                  v[r+1].first-v[r].first<=k &&
                  v[r+1].first-v[l].first<=k)
                r++;

            up[l][0]=r;
        }

        for(int j=1;j<18;j++){
            for(int i=0;i<n;i++){
                up[i][j]=up[up[i][j-1]][j-1];
            }
        }

        vector<int> ans;

        for(auto &x:q){

            int l=pos[x[0]];
            int r=pos[x[1]];

            if(l>r) swap(l,r);

            if(l==r){
                ans.push_back(0);
                continue;
            }

            int cur=l;
            int cnt=0;

            for(int j=17;j>=0;j--){

                if(up[cur][j]<r){
                    cnt+=(1<<j);
                    cur=up[cur][j];
                }
            }

            if(up[cur][0]>=r)
                ans.push_back(cnt+1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};