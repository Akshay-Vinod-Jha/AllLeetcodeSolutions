/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int returnMaxIndex(vector<int>& nums,int start,int end){
        int maxis=INT_MIN;
        int maxindex=-1;
        for(int i=start;i<=end;i++){
            if(nums[i] > maxis){
                maxis=nums[i];
                maxindex=i;
            }
        }
        return maxindex;
    }
    TreeNode* recfun(int start,int end,vector<int>& nums){
        if(start>end) return nullptr;
        int c=returnMaxIndex(nums,start,end);
        TreeNode* dummy=new TreeNode(nums[c]);
        dummy->left=recfun(start,c-1,nums);
        dummy->right=recfun(c+1,end,nums);
        return dummy;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int c=returnMaxIndex(nums,0,nums.size()-1);
        TreeNode* head=new TreeNode(nums[c]);
        head->left=recfun(0,c-1,nums);
        head->right=recfun(c+1,nums.size()-1,nums);
        return head;
    }
};