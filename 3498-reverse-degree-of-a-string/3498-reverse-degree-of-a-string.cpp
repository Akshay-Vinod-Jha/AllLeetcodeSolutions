class Solution {
public:
    int reverseDegree(string s) {
        int retme = 0;
        int index = 1;
        for(auto& ch:s){
            int score = ch - 'a';
            int cons = 26 - score;
            retme += (index*cons);
            index++;
        }
        return retme;
    }
};