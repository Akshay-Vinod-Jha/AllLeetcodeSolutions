class Solution {
public:
    int countCollisions(string directions) {
       int leftstart=0,length=directions.length();
       while(leftstart<length && directions[leftstart]=='L') leftstart++;
       int rightend=length-1;
       while(rightend>=0 && directions[rightend]=='R') rightend--;
       int counttoreturn=0;
       for(int i=leftstart;i<=rightend;i++){
            if(directions[i]!='S') counttoreturn++;
       } 
       return counttoreturn;
    }
};