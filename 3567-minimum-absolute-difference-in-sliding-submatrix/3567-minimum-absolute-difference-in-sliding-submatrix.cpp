class Solution {
public:
    int findminabsdiff(set<int>& a){
        if(a.size() < 2) return 0;

        int mindiff = INT_MAX;

        auto it = a.begin();
        auto prev = it;
        it++;

        while(it != a.end()){
            mindiff = min(mindiff, abs(*it - *prev));
            prev = it;
            it++;
        }

        return mindiff;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int row = grid.size();
        int col = grid[0].size();
        
        if(k == 1){
            return vector<vector<int>>(row, vector<int>(col, 0));
        }

        vector<vector<int>> retme;

        for(int i = 0; i <= row - k; i++){
            vector<int> b;

            for(int j = 0; j <= col - k; j++){

                int nexti = i + k;
                int nextj = j + k;

                set<int> a;

                for(int starti = i; starti < nexti; starti++){
                    for(int startj = j; startj < nextj; startj++){
                        a.insert(grid[starti][startj]);
                    }
                }

                b.push_back(findminabsdiff(a));
            }

            retme.push_back(b);
        }

        return retme;
    }
};