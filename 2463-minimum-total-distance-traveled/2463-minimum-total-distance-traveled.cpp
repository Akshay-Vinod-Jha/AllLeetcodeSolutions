class Solution {
public:
    long long rechelper(
        int currentrobotindex,
        int currentfactoryindex,
        int maxrobotindex,
        int maxfactoryindex,
        int usedforcurrentfactoryindex,
        vector<int>& robot,
        vector<vector<int>>& factory,
        vector<vector<vector<long long>>>& dp
    ){
        if(currentrobotindex >= maxrobotindex) return 0;
        if(currentfactoryindex >= maxfactoryindex) return LLONG_MAX;

        if(dp[currentrobotindex][currentfactoryindex][usedforcurrentfactoryindex] != -1)
            return dp[currentrobotindex][currentfactoryindex][usedforcurrentfactoryindex];

        long long retme = LLONG_MAX;
        if(usedforcurrentfactoryindex < factory[currentfactoryindex][1]){
            long long next = rechelper(
                currentrobotindex + 1,
                currentfactoryindex,
                maxrobotindex,
                maxfactoryindex,
                usedforcurrentfactoryindex + 1,
                robot,
                factory,
                dp
            );
            if(next != LLONG_MAX){
                retme = min(retme,
                    abs((long long)robot[currentrobotindex] - factory[currentfactoryindex][0]) + next
                );
            }
        }
        long long skip = rechelper(
            currentrobotindex,
            currentfactoryindex + 1,
            maxrobotindex,
            maxfactoryindex,
            0,
            robot,
            factory,
            dp
        );
        retme = min(retme, skip);
        return dp[currentrobotindex][currentfactoryindex][usedforcurrentfactoryindex] = retme;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        int maxrobotindex = robot.size();
        int maxfactoryindex = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<vector<long long>>> dp(
            maxrobotindex,
            vector<vector<long long>>(maxfactoryindex, vector<long long>(101, -1))
        );
        return rechelper(0, 0, maxrobotindex, maxfactoryindex, 0, robot, factory, dp);
    }
};