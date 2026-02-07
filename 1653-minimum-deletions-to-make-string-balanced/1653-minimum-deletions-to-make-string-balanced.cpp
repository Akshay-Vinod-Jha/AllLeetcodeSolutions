class Solution {
public:
    int minimumDeletions(string s) {
           int b = 0;
           int returnme = 0;
           int size = s.length();
           
           for(int i=0;i<size;i++){
                if(s[i]=='b') b++;
                else{
                    returnme = min(returnme+1,b);
                }
           }
           return returnme;
    }
};