class Solution {
public:
    int maxamongtwo(string& s,char first,char second){
        unordered_map<int,int> considerme;
        considerme[0] = -1;   

        int countfirst = 0;
        int countsecond = 0;
        int returnme = 0;
        int size = s.length();

        for(int i=0;i<size;i++){
            if(s[i]==first){
                countfirst++;
            }else if(s[i]==second){
                countsecond++;
            }else{
                countfirst = 0;
                countsecond = 0;
                considerme.clear();
                considerme[0] = i;
                continue;
            }

            int diff = countfirst - countsecond;
            if(considerme.count(diff)){
                returnme = max(returnme,i-considerme[diff]);
            }else{
                considerme[diff]=i;
            }
        }
        return returnme;
    }

    int longestBalanced(string s) {

        int size = s.length();
        int maxreturn = 0;
        int count = 1;
        for(int i=1;i<size;i++){
            if(s[i]==s[i-1]){
                count++;
            }else{
                maxreturn = max(maxreturn,count);
                count=1;
            }
        }
        maxreturn = max(maxreturn,count);

        maxreturn = max(maxreturn,maxamongtwo(s,'a','b'));
        maxreturn = max(maxreturn,maxamongtwo(s,'b','c'));
        maxreturn = max(maxreturn,maxamongtwo(s,'a','c'));

        map<pair<int,int>,int> iammap;
        iammap[{0,0}] = -1;  

        int counta = 0;
        int countb = 0;
        int countc = 0;

        for(int i=0;i<size;i++){
            if(s[i]=='a') counta++;
            else if(s[i]=='b') countb++;
            else countc++;

            int diffab = counta - countb;
            int diffac = counta - countc;

            if(iammap.count({diffab,diffac})){
                maxreturn = max(maxreturn,i-iammap[{diffab,diffac}]);
            }else{
                iammap[{diffab,diffac}] = i;
            }
        }

        return maxreturn;
    }
};
