class Solution {
public:
    bool countlogic(vector<int>& a){
        int tocompare = *max_element(a.begin(),a.end());
        for(int i=0;i<26;i++){
            if(a[i]!=0 && tocompare!=a[i]) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        vector<int> a(26,0);
       int size = s.length();
       int maxl = 0;
       for(int i=0;i<size;i++){
            for(int i=0;i<26;i++) a[i]=0;
            for(int j=i;j<size;j++){
                a[s[j]-'a']++;
                if(countlogic(a)) maxl=max(maxl,j-i+1);
            }
       } 
       return maxl;
    }
};