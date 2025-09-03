class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int current = 0;
        int start = current+1;
        while(current <  intervals.size()-1){
            if(intervals[current][1]>=intervals[start][0]){
                intervals[current][1]= intervals[start][1] > intervals[current][1] ? intervals[start][1] :intervals[current][1];
                intervals.erase(intervals.begin()+start);
            }else{
                current = start;
                start = current+1;
            }
        }
        return intervals;
    }
};