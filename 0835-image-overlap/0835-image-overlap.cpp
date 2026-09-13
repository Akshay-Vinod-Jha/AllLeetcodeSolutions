class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        map< pair<int,int> , int  > m;
        vector< pair<int,int> > first;
        vector< pair<int,int> > second;
        int rowsf = img1.size();
        int colsf = img1[0].size();
        int rowss = img2.size();
        int colss = img2[0].size();
        
        for(int i=0;i<rowsf;i++){
            for(int j=0;j<colsf;j++){
                if(img1[i][j]==1) first.push_back({i,j});
            }
        }

        for(int i=0;i<rowss;i++){
            for(int j=0;j<colss;j++){
                if(img2[i][j]==1) second.push_back({i,j});
            }
        }



        for(auto& i:first){
            for(auto& j:second){
                int dx = i.first - j.first;
                int dy = i.second - j.second;
                m[{dx,dy}]++;
            }
        }

        int retme = INT_MIN;
        for(auto& i:m){
            retme = max(retme,i.second);
        }

        return retme==INT_MIN?0:retme;
    }
};