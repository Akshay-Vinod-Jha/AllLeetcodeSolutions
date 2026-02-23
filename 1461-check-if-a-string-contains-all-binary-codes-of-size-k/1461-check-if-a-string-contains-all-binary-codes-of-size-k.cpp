class Solution {
public:
    bool hasAllCodes(string s, int k) {
        map<string,int> m;
        int sizeis = s.size();
        for(int i=0;i<=sizeis-k;i++){

            m[s.substr(i,k)]++;

        } 

        return m.size() == pow(2,k);

    }
};