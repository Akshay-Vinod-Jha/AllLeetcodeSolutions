class Solution {
public:

    bool ispalindrome(string& s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int helper( 
        string& s,
        int start, // changhe
        int end , // change
        int diff ,
        int size,
        vector<vector<int>>& dp
    ){


        if(start>=size || end>=size) return 0;

        if(dp[start][end]!=-1) return dp[start][end];

        if(ispalindrome(s,start,end)){

            int take = 1 + helper(s,end+1,end+diff,diff,size,dp);
            int increase = helper(s,start,end+1,diff,size,dp);
            int goahead = helper(s,start+1,end+1,diff,size,dp);
            return dp[start][end]=  max({take,increase,goahead});


        }else{

            int increase = helper(s,start,end+1,diff,size,dp);
            int goahead = helper(s,start+1,end+1,diff,size,dp);
            return dp[start][end] = max({increase,goahead});

        }


        return dp[start][end] =  0;

    }
    int maxPalindromes(string s, int k) {

        int size= s.size();
        if(k==1) return size;
        vector<vector<int>> dp(size+1,vector<int>(size+1,-1));
        return helper(
            s,0,k-1,k,size,dp
        );
        

    }
};