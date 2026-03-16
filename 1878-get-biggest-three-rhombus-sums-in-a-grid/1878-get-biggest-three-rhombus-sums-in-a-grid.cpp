class Solution {
public:

    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        set<int> st;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                st.insert(grid[i][j]);
                int len = 1;
                while(i + 2*len < row && j-len >= 0 && j+len < col){
                    int sum = 0;

                    for(int k = 0; k < len; k++)
                        sum += grid[i+k][j+k];

                    for(int k = 0; k < len; k++)
                        sum += grid[i+len+k][j+len-k];

                    for(int k = 0; k < len; k++)
                        sum += grid[i+2*len-k][j-k];

                    for(int k = 0; k < len; k++)
                        sum += grid[i+len-k][j-len+k];
                    st.insert(sum);
                    len++;
                }
            }
        }
        vector<int> ans;
        for(auto it = st.rbegin(); it != st.rend() && ans.size() < 3; it++){
            ans.push_back(*it);
        }
        return ans;
    }
};