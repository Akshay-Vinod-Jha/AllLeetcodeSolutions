class Solution {
public:
    vector<vector<long long>> dp;
    long long recfun(int currentindex,int format,vector<int>& nums,int actualsize){

        if(currentindex==actualsize){
            if(format==3){
                return 0;
            }else{
                return LLONG_MIN/2;
            }
        }

        if(dp[currentindex][format]!=LLONG_MIN){
            return dp[currentindex][format];
        }

        long long take = LLONG_MIN/2;
        long long skip = LLONG_MIN/2;

        if(format == 0){
            skip = recfun(currentindex+1,0,nums,actualsize);
        }

        if(format == 3){
            take = nums[currentindex];
        }

        if(currentindex+1 < actualsize){

            int currentele = nums[currentindex];
            int nextele = nums[currentindex+1];

            if(format == 0 && currentele<nextele){
                take = max(take,currentele+recfun(currentindex+1,1,nums,actualsize));
            }else if(format==1){

                if(currentele<nextele){
                    take = max(take,currentele+recfun(currentindex+1,1,nums,actualsize));
                }else if(currentele>nextele){
                    take = max(take,currentele+recfun(currentindex+1,2,nums,actualsize));   
                }

            }else if(format == 2){
                if(nextele<currentele){
                    take = max(take,currentele+recfun(currentindex+1,2,nums,actualsize));
                }else if(nextele>currentele){
                    take = max(take,currentele+recfun(currentindex+1,3,nums,actualsize));
                }
            }else if(format==3 && nextele>currentele){
                take = max(take,currentele+recfun(currentindex+1,3,nums,actualsize));
            }

        }

        dp[currentindex][format] = max(take,skip);
        return dp[currentindex][format];
    }   
    long long maxSumTrionic(vector<int>& nums) {
        int size = nums.size();
        dp.assign(size+1,vector<long long>(4,LLONG_MIN));
        return recfun(0,0,nums,size);
    }
};