class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<long long> converted(row*col,0);
        vector<long long> pref(row*col,1);
        vector<long long> suffix(row*col,1);

        int index = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                converted[index] = grid[i][j];
                index++;
            }
        }
        index = 1;
        while(index < row*col){
            pref[index] = ((long long)pref[index-1] * (long long)converted[index-1]) % 12345;
            index++;
        }
        index = row*col - 2;
        while(index >= 0){
            suffix[index] = ((long long)suffix[index+1] * (long long)converted[index+1]) % 12345;
            index--;
        }

        vector<vector<int>> retme(row,vector<int>(col,0));

        index = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                retme[i][j] = ((long long)pref[index] * (long long)suffix[index]) % 12345;
                index++;
            }
        }

        return retme;
    }
};