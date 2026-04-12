class Solution {
public:

    pair<int,int> getcoordinates(char ch){
        int numberformat = ((int)ch - (int)'A');
        return {numberformat/6,numberformat%6};
    }

    int returnDistance(int x1,int y1,int x2,int y2){
        if(x1 == -1 && y1 == -1) return 0;
        return abs(x1-x2)+abs(y1-y2);
    }

    int helper(int currentindex,int x1,int y1,int x2,int y2,string& word,int maxindex,vector<vector<vector<vector<vector<int>>>>>& dp){
        if(currentindex>=maxindex) return 0;
        if(dp[currentindex][x1+1][y1+1][x2+1][y2+1]!=-1) return dp[currentindex][x1+1][y1+1][x2+1][y2+1];
        pair<int,int> coordinates = getcoordinates(word[currentindex]);

        if(x1==-1 && y1==-1 && x2==-1 && y2==-1){
            int useFirst = helper(currentindex+1,
                                  coordinates.first,coordinates.second,
                                  x2,y2,word,maxindex,dp);

            int useSecond = helper(currentindex+1,
                                   x1,y1,
                                   coordinates.first,coordinates.second,
                                   word,maxindex,dp);

            return dp[currentindex][x1+1][y1+1][x2+1][y2+1]=min(useFirst,useSecond);
        }

        if(x2==-1 && y2==-1){
            int useSecond = helper(currentindex+1,
                                   x1,y1,
                                   coordinates.first,coordinates.second,
                                   word,maxindex,dp);

            int useFirst = returnDistance(x1,y1,coordinates.first,coordinates.second)
                         + helper(currentindex+1,
                                  coordinates.first,coordinates.second,
                                  x2,y2,
                                  word,maxindex,dp);

            return dp[currentindex][x1+1][y1+1][x2+1][y2+1]=min(useFirst,useSecond);
        }

        int useFirst = returnDistance(x1,y1,coordinates.first,coordinates.second)
                     + helper(currentindex+1,
                              coordinates.first,coordinates.second,
                              x2,y2,
                              word,maxindex,dp);

        int useSecond = returnDistance(x2,y2,coordinates.first,coordinates.second)
                      + helper(currentindex+1,
                               x1,y1,
                               coordinates.first,coordinates.second,
                               word,maxindex,dp);

        return dp[currentindex][x1+1][y1+1][x2+1][y2+1]=min(useFirst,useSecond);
    }

    int minimumDistance(string word) {

        vector<vector<vector<vector<vector<int>>>>> dp(
            301,
            vector<vector<vector<vector<int>>>>(
                7,
                vector<vector<vector<int>>>(
                    7,
                    vector<vector<int>>(
                        7,
                        vector<int>(7, -1)
                    )
                )
            )
        );
        return helper(0,-1,-1,-1,-1,word,word.size(),dp);
    }
};