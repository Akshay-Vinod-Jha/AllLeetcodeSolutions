class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
            
        int row = grid.size();
        int col = grid[0].size();

        vector<long long> horsum(row,0);
        for(int i=0;i<row;i++){
            long long colans = 0;
            for(int j=0;j<col;j++){
                colans += grid[i][j];
            }
            horsum[i] = colans;
        }

        vector<long long> versum(col,0);
        for(int i=0;i<col;i++){
            long long versuminterior = 0;
            for(int j=0;j<row;j++){
                versuminterior += grid[j][i];
            }
            versum[i] = versuminterior;
        }

        long long totalhorsum = 0;
        for(int i=0;i<row;i++){
            totalhorsum += horsum[i];
        }

        long long totalversum = 0;
        for(int i=0;i<col;i++){
            totalversum += versum[i];
        }

        long long currentsum = 0;

        for(int i=0;i<row-1;i++){
            currentsum += horsum[i];
            long long temp = totalhorsum - currentsum;
            if(currentsum == temp) return true;
        }

        currentsum = 0;

        for(int i=0;i<col-1;i++){
            currentsum += versum[i];
            long long temp = totalversum - currentsum;
            if(currentsum == temp) return true;
        }

        return false;
    } 
};