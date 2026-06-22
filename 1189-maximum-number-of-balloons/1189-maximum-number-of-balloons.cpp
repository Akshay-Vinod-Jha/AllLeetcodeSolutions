class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string hehe = "ballon";
        unordered_map<char,int> m;
        for(auto& i:text){
            m[i]++;
        }
        int minis = INT_MAX;
        for(auto& i:hehe){

            if(m[i]==0 || m['l']<2 || m['o']<2) return 0;

            if(i=='l'){
                minis = min(minis,m['l']/2);
            }else if(i=='o'){
                minis = min(minis,m['o']/2);
            }else{
                minis = min(minis,m[i]);
            }
        }
        return minis;
    }
};