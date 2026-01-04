class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int grandtotal = 0;
        for(auto& num:nums){
            int count = 0;
            int sum = 0;
            for(int i=1;i*i<=num;i++){
                if(num%i == 0){
                    count++;
                    sum += i;
                    int secondnum = num/i;
                    if(secondnum != i){
                        count++;
                        sum += secondnum;
                    }
                }

                if(count>4) break;
            }
            if(count==4) grandtotal+= sum;
        }
        return grandtotal;
    }
};