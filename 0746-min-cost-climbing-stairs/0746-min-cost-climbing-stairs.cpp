class Solution {
public:
    int helper(
      int index,
      vector<int>& cost,
      int maxindex,
      vector<int>& dp
      ){
      if(index>maxindex) return 0;


      if(dp[index]!=-1) return dp[index];

      int onestep = cost[index] + helper(index+1,cost,maxindex,dp);
      int twostep = cost[index] + helper(index+2,cost,maxindex,dp);
      return dp[index]=min(onestep,twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
      
        vector<int> dp(cost.size(),-1);

        return min(
          helper(0,cost,cost.size()-1,dp),
          helper(1,cost,cost.size()-1,dp)
          );
    } 
};