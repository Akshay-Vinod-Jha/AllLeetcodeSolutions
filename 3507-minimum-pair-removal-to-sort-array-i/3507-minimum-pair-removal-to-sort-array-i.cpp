#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool issorted(vector<int>& nums){
        int size = nums.size();
        for(int i=1;i<size;i++){
            if(nums[i] < nums[i-1]) return false;
        }
        return true;
    }

    int sol(vector<int>& nums){
         
        int size = nums.size();

        int bhetla = -1;
        for(int i=1;i<size;i++){
            if(nums[i] < nums[i-1]){
                bhetla = i;
                break;
            }
        }

        if(bhetla == -1) return 0;

        int count = 0;

        while(!issorted(nums)){
            size = nums.size();

            int bhetla = -1;
            for(int i=1;i<size;i++){
                if(nums[i] < nums[i-1]){
                    bhetla = i;
                    break;
                }
            }

            int minvalue = INT_MAX;
            int slidingindex = -1;

            for(int i=0;i<size-1;i++){
                int sumis = nums[i] + nums[i+1];
                if(sumis < minvalue){
                    minvalue = sumis;
                    slidingindex = i;
                }
            }

            nums[slidingindex] = minvalue;

            for(int i=slidingindex+1;i<size-1;i++){
                nums[i] = nums[i+1];
            }

            nums.pop_back();
            count++;
        }

        return count;
    }

    int minimumPairRemoval(vector<int>& nums) {
        return sol(nums);
    }
};
