class Solution {
public:
    char processStr(string s, long long k) {
        
        long long  length = 0;

        for(auto& c:s){
            if(c=='*'){
                if(length - 1 >=0 ){
                    length--;
                }
            }
            else if(c=='#'){
                length *=2;
            }
            else if(c=='%'){}
            else{
                length++;
            }
        }

        if(k>=length) return '.';

        int size = s.size();

        for(int i=size-1;i>=0;i--){
            char c = s[i];
            if(c=='*'){
                length++;
            }
            else if(c=='#'){
                length /=2;
                if(k - length  >= 0 ){
                    k = k - length;
                }
            }
            else if(c=='%'){
                k = length - k - 1;
            }
            else{
                length--;
            }

            if(k==length) return s[i];
        }

        return '.';

    }
};