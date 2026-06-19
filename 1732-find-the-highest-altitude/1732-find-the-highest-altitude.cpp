class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxis = 0;
        int num = 0;
        for(auto& i:gain){
            num += i;
            maxis = max(maxis,num);
        }
        return maxis;

    }
};