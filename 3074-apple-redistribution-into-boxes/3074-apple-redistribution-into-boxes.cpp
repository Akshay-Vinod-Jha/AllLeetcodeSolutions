class Solution {
public:
    int returnSum(vector<int>& a){
        int sum=0;
        for(auto& ind:a) sum+=ind;
        return sum;
    }
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=returnSum(apple);
        int returnme=0,ini=0;
        sort(capacity.begin(),capacity.end());
        reverse(capacity.begin(),capacity.end());
        for(auto& ind:capacity){
            ini+=ind;returnme++;
            if(ini<sum) continue;
            else break;
        }
        return returnme;
    }
};