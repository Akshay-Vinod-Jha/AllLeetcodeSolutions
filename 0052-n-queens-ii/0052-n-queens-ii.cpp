class Solution {
public:
    void recfun(int colcurr,int collast,vector<string> eachitr,vector<vector<string>> &returnme,vector<int> leftdekho,vector<int> upperdekho,vector<int> nichedekho,int& count){
        if(colcurr==collast){
            count++;
            return;
        }
        for(int i=0;i<collast;i++){
            if(leftdekho[i]!=1 && upperdekho[i+colcurr]!=1 && nichedekho[(collast-1-i)+colcurr]!=1){
                eachitr[i][colcurr]='Q';
                leftdekho[i]=1;
                upperdekho[i+colcurr]=1;
                nichedekho[(collast-1-i)+colcurr]=1;
                recfun(colcurr+1,collast,eachitr,returnme,leftdekho,upperdekho,nichedekho,count);
                eachitr[i][colcurr]='.';
                leftdekho[i]=0;
                upperdekho[i+colcurr]=0;
                nichedekho[(collast-1-i)+colcurr]=0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> returnme;
        vector<int> leftdekho(n,0);
        vector<int> upperdekho(2*n -1,0);
        vector<int> nichedekho(2*n-1,0);
        vector<string> eachitr;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp+=".";
            }
            eachitr.push_back(temp);
        } 
        int count=0;
        recfun(0,n,eachitr,returnme,leftdekho,upperdekho,nichedekho,count);
        return count;
    }
};