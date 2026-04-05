class Solution {
public:
    bool judgeCircle(string moves) {
        int starti = 0 ,  startj = 0;
        int size = moves.size();
        for(int i=0;i<size;i++){
            char dir = moves[i];
            if(dir=='U') starti--;
            else if(dir=='R') startj++;
            else if(dir=='L') startj--;
            else starti++;
        }
        return (starti==0 && startj==0);
    }
};