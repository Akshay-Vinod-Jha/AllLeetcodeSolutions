class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums.at(i)<0){
                if((i-abs(nums.at(i)))>=0)
                    result[i]=nums.at(i-abs(nums.at(i)));
                else
                result[i] = nums.at(((i - (abs(nums.at(i)) % nums.size())) + nums.size()) % nums.size());

            }
            else if(nums.at(i)>0){
                result[i]=nums.at((i+nums.at(i))%nums.size());
            }
            else{
                result[i]=nums.at(i);
            }
        }
    return result;
    }
};