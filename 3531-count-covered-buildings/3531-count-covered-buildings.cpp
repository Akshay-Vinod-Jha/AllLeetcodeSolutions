class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,vector<vector<int>>> x, y;
        for (auto& ind : buildings) {
            x[ind[0]].push_back(ind);
            y[ind[1]].push_back(ind);
        }
        for (auto &ind : x) sort(ind.second.begin(), ind.second.end());
        for (auto &ind : y) sort(ind.second.begin(), ind.second.end());
        map<vector<int>, pair<int,int>> a;
        for (auto &ind : x) {
            int length = ind.second.size();
            for (int i = 1; i < length - 1; i++) 
                a[ind.second[i]].first++;
        }
        for (auto &ind : y) {
            int length = ind.second.size();
            for (int i = 1; i < length - 1; i++) 
                a[ind.second[i]].second++;
        }
        int count = 0;
        for (auto &ind : a) {
            if (ind.second.first > 0 && ind.second.second > 0)
                count++;
        }
        return count;
    }
};
