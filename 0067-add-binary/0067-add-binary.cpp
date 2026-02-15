class Solution {
public:
    pair<int,int> returnres(int num1 , int num2){
        if(num1==0 && num2==0) return {0,0};
        else if((num1==0 && num2==1) || (num1==1 && num2==0)) return {0,1};
        return {1,0};
    }

    string addBinary(string a, string b) {

        int carry = 0;
        int size1 = a.length();
        int size2 = b.length();
        int minlength = min(size1, size2);
        string returnme = "";
        for(int i = 0; i < minlength; i++){
            int num1 = a[size1 - 1 - i] - '0';
            int num2 = b[size2 - 1 - i] - '0';

            pair<int,int> res1 = returnres(num1, num2);
            pair<int,int> res2 = returnres(carry, res1.second);

            carry = (res1.first == 1 || res2.first == 1) ? 1 : 0;
            returnme += char('0' + res2.second);
        }
        if(size1 > size2){
            for(int i = size1 - minlength - 1; i >= 0; i--){
                int num1 = a[i] - '0';
                pair<int,int> res = returnres(num1, carry);
                carry = res.first;
                returnme += char('0' + res.second);
            }
        } else {
            for(int i = size2 - minlength - 1; i >= 0; i--){
                int num1 = b[i] - '0';
                pair<int,int> res = returnres(num1, carry);
                carry = res.first;
                returnme += char('0' + res.second);
            }
        }
        if(carry == 1) returnme += '1';
        reverse(returnme.begin(), returnme.end());
        return returnme;
    }
};
