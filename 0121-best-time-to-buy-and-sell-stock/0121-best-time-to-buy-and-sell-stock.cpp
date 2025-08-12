class Solution {
public:
    int maxProfit(vector<int>& prices) {
            int profit = 0 , iammin = prices[0],length = prices.size();
            for(int i=1;i<length;i++){
                iammin = min(iammin,prices[i]);
                if(prices[i] - iammin >0 ){
                    profit = max( profit , prices[i]-iammin);
                }
            }
            return profit;
    }
};