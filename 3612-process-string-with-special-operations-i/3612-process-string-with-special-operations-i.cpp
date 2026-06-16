class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(auto& i:s){
            if(i=='*'){
                if(result.size()>0){
                    result.pop_back();
                }
            }
            else if(i=='#'){
                result += result;
            }
            else if(i=='%'){
                reverse(result.begin(),result.end());
            }
            else{
                result += i;
            }
        }
        return result;
    }
};