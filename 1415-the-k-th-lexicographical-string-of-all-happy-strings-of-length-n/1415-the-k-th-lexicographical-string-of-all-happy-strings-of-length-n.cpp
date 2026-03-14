class Solution {
public:
    void recfun(string main,int clen,int n,vector<string>& a,vector<char>& b){
        if(clen==n){
            a.push_back(main);
            return ;
        }

        int mainsize = main.size();
        char lastchar = main[mainsize-1];
        for(int i=0;i<3;i++){
            if(b[i]!=lastchar){
                recfun(main+b[i],clen+1,n,a,b);
            }
        }

    }
    string getHappyString(int n, int k) {
        vector<string> a;
        vector<char> b;
        b.push_back('a');
        b.push_back('b');
        b.push_back('c');
        recfun("a",1,n,a,b);
        recfun("b",1,n,a,b);
        recfun("c",1,n,a,b);
        sort(a.begin(),a.end());
        
        if(k>a.size()) return "";
        return a[k-1];

    }
};