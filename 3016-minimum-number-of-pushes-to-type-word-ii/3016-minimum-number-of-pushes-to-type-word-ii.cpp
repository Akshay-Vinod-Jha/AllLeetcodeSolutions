class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> m;
        for(auto& i:word) m[i]++;
        vector< pair<int,int> > v;
        for(auto& i:m){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());reverse(v.begin(),v.end());
        // 1*8 2*8 3*8 4*2
        int res = 0;
        int index = 0;
        int size = v.size();
        for(int i=0;i<min(8,size);i++){
            res += v[i].first*1;
        }
        for(int i=8;i<min(16,size);i++){
            res += v[i].first*2;
        }
        for(int i=16;i<min(24,size);i++){
            res += v[i].first*3;
        }
        for(int i=24;i<min(26,size);i++){
            res += v[i].first*4;
        }
        return res;
    }
};