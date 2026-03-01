class Solution {
public:
    int minPartitions(string n) {
        int length=n.size();
        int toreturn=INT_MIN;
        for(int i=0;i<length;i++){
            toreturn=max(toreturn,n[i]-'0');
        }
        return toreturn;
    }
};
