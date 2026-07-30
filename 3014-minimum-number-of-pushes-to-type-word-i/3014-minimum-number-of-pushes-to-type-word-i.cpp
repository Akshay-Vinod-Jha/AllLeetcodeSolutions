class Solution {
public:
    int minimumPushes(string word) {
        int size = word.size();
        int retme = 0;
        int minis = min(size,8);
        if(minis>0){
            size = size - minis;
            retme += minis; 
        }
        minis = min(size,8);
        if(minis>0){
            size = size - minis;
            retme += 2*minis; 
        }
        minis = min(size,8);
        if(minis>0){
            size = size - minis;
            retme += 3*minis; 
        }
        minis = min(size,8);
        if(minis>0){
            size = size - minis;
            retme += 4*minis; 
        }
        return retme;
    }
};