class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int stlen = s.length();
        unordered_map<string,string> hehe;
        for(auto& indstring:knowledge){
          hehe[indstring[0]] = indstring[1];
        }
        string retme = "";
        int i =0;
        while(i<stlen){
          if(s[i]=='('){
            int j = i+1;
            string iskey = "";
            while(j<stlen && s[j]!=')'){
                iskey+= s[j];
                j++;
            }
            i = j;
            retme+=hehe.count(iskey) > 0 ? hehe[iskey] : "?";
          }
          else{
            retme += s[i];
          }
          i++;
        }

        return retme;
        
    }
};