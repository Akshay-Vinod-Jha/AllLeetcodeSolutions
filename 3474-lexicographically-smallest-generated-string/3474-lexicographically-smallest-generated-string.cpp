class Solution {
public:
    bool isvalid(int startind,string& source,string& comparewith,int comparewithlen){
        for(    
            int i=startind,j=0;j<comparewithlen;j++,i++
            ){
            if(source[i]!=comparewith[j]) return true;
        }
        return false;
    }
    string generateString(string str1, string str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        int reqlen = len1+len2-1;
        string retme(reqlen,'-');


        for(int i=0;i<len1;i++){
            if(str1[i]=='T'){
                for(int start=i,j=0;j<len2;j++,start++){
                    if(retme[start]!='-' && retme[start]!=str2[j]) return "";
                    retme[start] = str2[j];
                }
            }
        }

        vector<bool> changeable(reqlen,false);
        for(int i=0;i<reqlen;i++){
            if(retme[i]=='-'){
                retme[i] = 'a';
                changeable[i] = true;
            }
        }

        for(int i=0;i<len1;i++){
            if(str1[i]=='F'){

                if(!isvalid(i,retme,str2,len2)){

                    bool changed = false;
                    for(int j=i+len2-1;j>=i;j--){
                        if(changeable[j]==true && retme[j]=='a'){
                            retme[j]='b';
                            changed = true;
                            break;
                        }
                    }
                    if(!changed) return "";

                }

            }
        }
        return retme;
    }
};