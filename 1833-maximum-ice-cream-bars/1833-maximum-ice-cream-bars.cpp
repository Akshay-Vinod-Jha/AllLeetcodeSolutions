class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int abhitak = 0;
        int count = 0;
        for(auto& i:costs){
            if(abhitak+i <= coins){ abhitak += i;count++;}
            else return count;
        }
        return count;
    }
};