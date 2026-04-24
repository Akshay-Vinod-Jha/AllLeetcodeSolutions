class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int leftcount = 0;
        int rightcount = 0;
        
        int size = moves.size();

        for(int i=0;i<size;i++){
            if(moves[i]=='L') leftcount--;
            else if(moves[i]=='R') leftcount++;
            else leftcount--;
        }

        for(int i=0;i<size;i++){
            if(moves[i]=='L') rightcount--;
            else if(moves[i]=='R') rightcount++;
            else rightcount++;
        }

        if(abs(leftcount)>abs(rightcount)) return abs(leftcount);
        return abs(rightcount);
    }
};