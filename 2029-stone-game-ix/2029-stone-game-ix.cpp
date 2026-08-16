class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count_one = 0 , count_two = 0 , count_zero=0;
        for(auto& i:stones){
            if(i%3==1) count_one++;
            else if(i%3==2) count_two++;
            else count_zero++;
        }

        if(count_zero%2==0) return count_one>0 && count_two>0;
        return abs(count_one-count_two)>2;
    }
};