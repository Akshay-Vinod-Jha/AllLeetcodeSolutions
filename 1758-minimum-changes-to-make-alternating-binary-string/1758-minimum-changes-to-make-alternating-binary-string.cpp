class Solution {
public:
    int minOperations(string s) {
        
        int count = 0;
        int size = s.size();
        char mi = '0';
        int pahila = 0;
        for(int i=0;i<size;i++){
            if(s[i] != mi) pahila++;
            mi = (mi=='0') ? '1' : '0';
        }
        mi = '1';
        int dusra = 0;
        for(int i=0;i<size;i++){
            if(s[i] != mi) dusra++;
            mi = (mi=='0') ? '1' : '0';
        }
        count = min(pahila,dusra);
        return count;

    }
};