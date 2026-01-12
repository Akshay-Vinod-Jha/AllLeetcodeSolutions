class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int length = points.size()-1;
        int count = 0;


        for(int i=0;i<length;i++){

            int x1 = points[i][0] , y1 = points[i][1] ;
            int x2 = points[i+1][0] , y2 = points[i+1][1];

            int xi = 0 , yi = 0;

            if(x1<x2) xi=1;
            else if(x1>x2) xi=-1;

            if(y1<y2) yi=1;
            else if(y1>y2) yi=-1;

            while(x1!=x2 && y1!=y2){
                count++;
                x1+=xi;
                y1+=yi;
            }

            while(x1!=x2){
                count++;
                x1+=xi;
            }

            while(y1!=y2){
                count++;
                y1+=yi;
            }
        }

        return count;
    }
};