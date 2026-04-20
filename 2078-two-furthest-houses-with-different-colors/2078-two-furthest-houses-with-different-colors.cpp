class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        unordered_map<int,vector<int>> a;
        int size = colors.size();
        for(int i=0;i<size;i++){
          a[colors[i]].push_back(i);
        }

        int retme = 0;

        for(auto& i:a){
          int ik = i.first;
          for(auto& j:a){
            int jk = j.first;
            if(ik==jk) continue;

            int ifirstele = i.second[0];
            int sizeofjvector = j.second.size();
            int jlastele = j.second[sizeofjvector-1];

            retme = max(retme,abs(jlastele - ifirstele));

          }
        }
        
        return retme;

    }
};