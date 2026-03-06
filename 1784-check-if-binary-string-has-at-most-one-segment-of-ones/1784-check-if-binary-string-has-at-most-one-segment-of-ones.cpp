class Solution {
public:
    bool checkOnesSegment(string s) {
        int length = s.length();
        int left = 0;
        while(left<length && s[left]=='1'){
            left++;
        }
        if(left==length) return true;
        while(left<length){
            if(s[left]=='1') return false;
            left++;
        }
        return true;
    }
};