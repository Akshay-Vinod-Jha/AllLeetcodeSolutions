class Solution {
public:

    int lowerbound_impl(
        vector<pair<int,pair<int,int>>>& hehe,
        int low,
        int comparewith
    ){
        int high = hehe.size()-1;
        int retme = -1;
        while(low<=high){

            int mid = low + (high-low)/2;
            if(hehe[mid].first>=comparewith){
                retme = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }

        } 

        return retme;
        

    }

    int helper(
        int  index,
        vector<pair<int,pair<int,int>>>& hehe,
        int size,
        vector<int>& dp
    ){


        if(index==size-1) return hehe[index].second.second;
        if(index>=size) return 0;


        if(dp[index]!=-1) return dp[index];

        int not_take = helper(index+1,hehe,size,dp);
        int lowerbound_impl_is = lowerbound_impl(hehe,index+1,hehe[index].second.first);
        int take = hehe[index].second.second;
        if(lowerbound_impl_is!=-1) take += helper(lowerbound_impl_is,hehe,size,dp);


        return   dp[index] = max(not_take,take);

    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,pair<int,int>>> hehe;
        int size = startTime.size();
        for(int i=0;i<size;i++){
            hehe.push_back({startTime[i],{endTime[i],profit[i]}});
        }
        sort(hehe.begin(),hehe.end());

        vector<int> dp(size,-1);

        return helper(0,hehe,hehe.size(),dp);
    }
};