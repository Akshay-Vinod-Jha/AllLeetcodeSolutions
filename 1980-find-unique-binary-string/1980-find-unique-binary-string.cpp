class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string retme = "";
        for(int i = 0; i < nums.size(); i++) {
            retme += (nums[i][i] == '0') ? '1' : '0';
        }
        return retme;
    }
};