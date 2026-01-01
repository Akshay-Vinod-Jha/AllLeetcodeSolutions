class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int length=digits.size(),carry=(digits[0]+1)/10;digits[0]=(digits[0]+1)%10;
        for(int i=1;i<length;i++){
            int sum = digits[i]+carry ;
            digits[i]=(sum)%10;
            carry=(sum)/10;
        }
        if(carry!=0) digits.push_back(carry);reverse(digits.begin(),digits.end());
        return digits;
    }
};