class Solution {
public:

    bool helper(int left,int right,int person1,int person2,int currentbari,vector<int>& nums){

        if(left>right){
            return person1>=person2;
        }
    

        if(currentbari==1){

            bool leftmai  = helper(left+1,right,person1+nums[left],person2,2,nums);
            bool rightmai = helper(left,right-1,person1+nums[right],person2,2,nums);
            return leftmai || rightmai;

        }else{
           bool leftmai =  helper(left+1,right,person1,person2+nums[left],1,nums);
           bool rightmai  =  helper(left,right-1,person1,person2+nums[right],1,nums);
           return leftmai && rightmai;
        }

        return false;

    }

    bool predictTheWinner(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        return helper(
            left,right,0,0,1,nums
        );

    }
};