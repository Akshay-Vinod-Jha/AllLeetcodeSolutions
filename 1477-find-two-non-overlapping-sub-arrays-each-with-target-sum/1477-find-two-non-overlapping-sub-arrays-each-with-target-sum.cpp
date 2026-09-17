class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int start = 0;
        int end = 0;
        int size = arr.size();
        int sum = 0;
        int minlen = INT_MAX;


        int retme = INT_MAX;
        vector<int> previousmin(size+1,INT_MAX);
        while(
            end<size
        ){
            sum += arr[end];
            while(sum>target){
                sum -= arr[start];
                start++;
            }
            
            if(sum==target){
                int lengthis = end - start + 1;

                if(start>0 && previousmin[start-1]!=INT_MAX){
                    retme = min(previousmin[start-1]+lengthis,retme);
                }

                minlen = min(minlen,lengthis);
            }

            previousmin[end] = minlen;

            end++;
        }
        return retme==INT_MAX?-1:retme;
    }
};