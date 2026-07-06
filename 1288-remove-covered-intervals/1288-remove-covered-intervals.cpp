class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector< pair<int,int> > s;
        map<int,vector<  pair<int,int> > > m;

        for(auto& i:intervals){
            m[i[0]].push_back({i[0],i[1]});
        }
        vector<vector<int>> newin;
         for(auto& i:m){
            sort(i.second.begin(),i.second.end());
            reverse(i.second.begin(),i.second.end());
            for(auto& j:i.second){
                newin.push_back({j.first,j.second});
            }
         }

        int size = 0;
        for(auto& i:newin){
            int istart = i[0];
            int iend = i[1];
            if(s.size()==0){
                s.push_back({istart,iend});
                size++;
            }
            else{
                int lstart = s[size-1].first;
                int lend = s[size-1].second;
                if(lstart<=istart && iend<=lend) continue;
                else{
                    s.push_back({istart,iend});
                    size++;
                } 
            }
        }

        for(auto& i:s) cout<<i.first<<"\t"<<i.second<<endl;

        return s.size();

    }
};