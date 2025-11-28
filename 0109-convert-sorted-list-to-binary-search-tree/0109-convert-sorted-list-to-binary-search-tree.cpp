/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void convertToVector(ListNode* head,vector<int>& v){
        ListNode* dummy=head;
        while(dummy){
            v.push_back(dummy->val);
            dummy=dummy->next;
        }
    }
    TreeNode* heightBalanced(vector<int>& v,int start,int end){
        if(start>end) return nullptr;
        int mid=(start+end)/2;
        TreeNode* rm = new TreeNode(v[mid]);
        rm->left=heightBalanced(v,start,mid-1);
        rm->right=heightBalanced(v,mid+1,end);
        return rm;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;convertToVector(head,v);
        return heightBalanced(v,0,v.size()-1);
    }
};