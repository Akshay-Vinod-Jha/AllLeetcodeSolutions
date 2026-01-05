class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0 ;
        int mnumber = INT_MAX;
        int ncount = 0;
        for(auto& i:matrix){
            for(auto& j:i){
                sum += abs(j);
                mnumber = min(mnumber,abs(j));
                if(j<0) ncount++;
            }
        }
        if(ncount%2 == 0) return sum;
        return sum - 2*mnumber;
    }
};