class Solution {
public:
    string getRevAndInv(string s){
        for(int i=0;i<s.length();i++){
            s[i]=s[i]=='0'?'1':'0';
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int recurrsivefunction(string &s,int actuallimit,int currentlimit,int indextoreturn){
        if(s.length()>=indextoreturn)return s[indextoreturn-1];
        if(currentlimit>actuallimit)return s[indextoreturn-1];
        s+="1"+getRevAndInv(s);
       return recurrsivefunction(s,actuallimit,currentlimit+1,indextoreturn);
    }
    char findKthBit(int n, int k) {
        string s="0";
        if(k==0)return '0';
       return recurrsivefunction(s,n,1,k);
    }
};