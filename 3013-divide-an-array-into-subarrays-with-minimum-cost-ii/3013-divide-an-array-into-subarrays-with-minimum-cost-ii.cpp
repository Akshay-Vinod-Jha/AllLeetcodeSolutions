class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        

        int size = nums.size();
        set<pair<int,int>> mainset;  // value and index 
        set<pair<int,int>> removed;
        int remaining = k - 1;

        int start = 1;
        long long result = LLONG_MAX;
        long long tempcount = 0;
        for(int i=start;i<=(start+dist);i++){
            mainset.insert({nums[i],i});
            tempcount+=nums[i];

            if(mainset.size()>remaining){
                auto maxis = *prev(mainset.end());
                tempcount -= maxis.first;
                removed.insert(maxis);
                mainset.erase(prev(mainset.end()));
            }
        }
        result = min(result,tempcount);

        start++;
        long long end = start + dist;
        while( end < size ){

            pair<int,int> naveen = {nums[end],end};
            if(!mainset.empty() && naveen < *prev(mainset.end())){
                auto toberemoved = *prev(mainset.end());
                mainset.erase(prev(mainset.end()));
                tempcount -= toberemoved.first;
                mainset.insert(naveen);
                tempcount += naveen.first;
                removed.insert(toberemoved);
            }else{
                removed.insert(naveen);
            }     

            if(mainset.count({nums[start-1],start-1})){
                tempcount -= nums[start-1];
                mainset.erase({nums[start-1],start-1});
                auto jomilahai = *removed.begin();
                removed.erase(removed.begin());
                mainset.insert(jomilahai);
                tempcount += jomilahai.first;
            }else{
                removed.erase({nums[start-1],start-1});
            }
            result = min(result,tempcount);
            start++;
            end = start + dist;
        }
        return nums[0]+result;
    }
};