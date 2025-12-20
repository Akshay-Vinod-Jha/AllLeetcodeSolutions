class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if(strs.size()==0) return 0;
        int ind = strs[0].length(),all=strs.size();
        int returnme=0;
        for(int i=0;i<ind;i++){
            bool allset=true;
            for(int j=0;j<all-1;j++){
                if(strs[j][i]<=strs[j+1][i]) continue;
                allset=false;
                break;
            }
            returnme+=!allset?1:0;
        }
        return returnme;
    }
};