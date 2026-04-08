class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
      int size = nums.size();
        long long modme = 1000000007;
        for(auto& indqueries:queries){
          int left = indqueries[0];
          int right = indqueries[1];
          int k = indqueries[2];
          int v = indqueries[3];
          int indexis = left;
          while(indexis<=right){
            nums[indexis] = ((long long)nums[indexis]*(long long)v)%modme;
            indexis += k;
          }
        }
        int retme = nums[0];
        for(int i=1;i<size;i++){
          retme = retme ^ nums[i];
        }
        return retme;
    }
};