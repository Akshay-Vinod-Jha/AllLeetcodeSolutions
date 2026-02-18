class Solution {
public:
    bool helper(int n){
        int compareme = n%2;
        n=n/2;
        while(n){
            int temp = n%2;
            if(temp==compareme) return false;
            else{
                compareme = temp;
            }
            n = n/2;
        }
        return true;
    }
    bool hasAlternatingBits(int n) {
        return helper(n);
    }
};