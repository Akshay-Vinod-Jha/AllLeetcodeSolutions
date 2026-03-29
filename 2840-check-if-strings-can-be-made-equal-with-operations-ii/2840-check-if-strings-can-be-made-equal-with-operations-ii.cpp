class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,pair<int,int>> even;
        unordered_map<char,pair<int,int>> odd;
        int size = s1.size();
        for(int i=0;i<size;i++){
            if(i%2==0){
                even[s1[i]].first++;
                even[s2[i]].second++;
            }else{
                odd[s1[i]].first++;
                odd[s2[i]].second++;
            }
        }
        for(auto& i:even){
            if(i.second.first!=i.second.second) return false;
        }
        for(auto& i:odd){
            if(i.second.first!=i.second.second) return false;
        }
        return true;
    }
};