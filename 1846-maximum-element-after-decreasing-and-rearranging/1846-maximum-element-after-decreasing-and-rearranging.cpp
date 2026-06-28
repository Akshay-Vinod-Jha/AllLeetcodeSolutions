class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {


        sort(arr.begin(),arr.end());
        // index + 1 =1> 0 + 1 => 1 index +1 <= value
        int maxis = INT_MIN;
        int size = arr.size();
        arr[0] = 1;
        for(int i=1;i<size;i++){
            arr[i] = min(arr[i],arr[i-1]+1);
        }

        return arr[size-1];

    }
};