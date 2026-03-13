class Solution {
public:

    bool possible(long long time, vector<int>& workerTimes, int mountainHeight){

        long long total = 0;

        for(int w : workerTimes){

            long long left = 0;
            long long right = 1e6;

            while(left <= right){

                long long mid = (left + right) / 2;

                long long t = (long long)w * mid * (mid + 1) / 2;

                if(t <= time){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }

            total += right;

            if(total >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long low = 0;
        long long high = 1e18;
        long long ans = high;

        while(low <= high){

            long long mid = (low + high) / 2;

            if(possible(mid, workerTimes, mountainHeight)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};