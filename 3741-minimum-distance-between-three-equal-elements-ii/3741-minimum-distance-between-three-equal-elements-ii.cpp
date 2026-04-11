class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> useme;
        int size = nums.size();
        for(int i=0;i<size;i++){
          useme[nums[i]].push_back(i);
        }
        int retme = INT_MAX;
        for(auto& induseme:useme){
          vector<int> req = induseme.second;
          int reqsize = req.size();
          if(reqsize<3) continue;
          int i = 0 , j = 2;
          while(j<reqsize){
            retme = min(retme,2*(req[j]-req[i]));
            i++;j++;
          }
        }
        return retme == INT_MAX ? -1 : retme;
    }
};