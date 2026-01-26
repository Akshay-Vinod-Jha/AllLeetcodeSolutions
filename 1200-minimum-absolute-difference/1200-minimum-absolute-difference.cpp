class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        int mindiff = INT_MAX , size = arr.size();
        for(int i=0;i<size-1;i++){
            mindiff = min(mindiff,arr[i+1]-arr[i]);
        }
        vector<vector<int>> toreturn;
        for(int i=0;i<size-1;i++){
            if( arr[i+1]-arr[i] == mindiff ) toreturn.push_back({arr[i],arr[i+1]});
        }
        return toreturn;



    }
};