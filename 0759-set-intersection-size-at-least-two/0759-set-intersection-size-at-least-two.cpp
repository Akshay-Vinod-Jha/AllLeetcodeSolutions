class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int length=intervals.size();
        for(int i=0;i<length-1;i++){
            for(int j=0;j<length-i-1;j++){
                if(intervals[j][1]>intervals[j+1][1]){
                    swap(intervals[j],intervals[j+1]);
                }
                if(intervals[j][1]==intervals[j+1][1] && intervals[j][0]<intervals[j+1][0]){
                    swap(intervals[j],intervals[j+1]);
                }
            }
        }
        int num1=-1,num2=-1,counttoreturn=0;
        for(auto& ind:intervals){
            bool num1there= (num1>=ind[0] && num1<=ind[1] ? true : false);
            bool num2there= (num2>=ind[0] && num2<=ind[1] ? true : false);
            if(num1there && num2there) continue;
            else if(num2there){
                counttoreturn++;
                num1=num2;
                num2=ind[1];
            }else{
                num1=ind[1]-1;
                num2=ind[1];
                counttoreturn+=2;
            }
        }
        return counttoreturn;
    }
};