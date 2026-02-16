class Solution {
public:
    int reverseBits(int n) {

        long long returnme = 0;
        vector<int> ans;

        while(n){
            int rem = n % 2;
            n = n / 2;
            ans.push_back(rem);
        }

        while(ans.size() < 32){
            ans.push_back(0);
        }

        int length = ans.size();

        for(int i = 0; i < length; i++){
            if(ans[i] == 1){
                returnme += pow(2, length - 1 - i);  
            }
        }

        return (int)returnme;
    }
};
