class Solution {
public:
    vector<int> returnEntireRow(int n){
        vector<int> temp;
        temp.push_back(1);
        int previousresult = 1;
        for(int i=1;i<n;i++){
            previousresult = previousresult * (n-i);
            previousresult = previousresult / i;
            temp.push_back(previousresult);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> returnme;
        for(int i=1;i<=numRows;i++){
            returnme.push_back(returnEntireRow(i));
        }
        return returnme;
    }
};