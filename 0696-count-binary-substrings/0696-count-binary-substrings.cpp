class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int size = s.length();
        int count = 0;
        
        for(int i=0;i<size;i++){
            
            char currentnum = s[i];
            int currentnumsum = 0;
            


            int j = i;
            while(j<size && s[j]==currentnum){
                currentnumsum++;
                j++;
            }


            char dusranum = s[j];
            int dusranumsum = 0;
            while(j<size && s[j]==dusranum){
                dusranumsum++;
                j++;
            }

            if(dusranumsum>=currentnumsum){
                count++;
            }
            
        }

        return count;

    }
};