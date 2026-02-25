class Solution {
public:

    int getonecount(int num){

        int count = 0;
        while(num){
            int rem = num%2;
            if(rem==1) count++;
            num = num/2;
        }
        return count;

    }

    vector<int> sortByBits(vector<int>& arr) {
        
        int size = arr.size();
        vector<pair<int,int>> a;
        for(int i=0;i<size;i++){

            a.push_back({getonecount(arr[i]),arr[i]});

        }

        sort(a.begin(),a.end());
        vector<int> b;
        for(int i=0;i<size;i++){
            b.push_back(a[i].second);
        }

        return b;

    }
};