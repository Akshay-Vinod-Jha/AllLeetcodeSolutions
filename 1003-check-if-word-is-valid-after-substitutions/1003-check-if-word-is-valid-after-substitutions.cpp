class Solution {
public:
    bool isValid(string s) {
        stack<int> saahe;
        int size = s.size();
        for(int i=0;i<size;i++){
            if(s[i]=='a') saahe.push(i);
        }
        while(!saahe.empty()){
            int topis = saahe.top();
            cout<<topis;
            cout<<endl;
            saahe.pop();
            if( topis<size && topis+1<size && topis+2<size &&  s[topis]=='a' && s[topis+1]=='b' && s[topis+2]=='c'){
                s.erase(topis,3);
                // all okay
            }else{
                return false;
            }
        }
        return s=="";
    }
};