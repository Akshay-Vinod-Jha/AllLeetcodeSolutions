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
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> a;
        ListNode* temp=head;
        while(temp){
            a.push_back(temp->val);
            temp=temp->next;
        }
        int length=a.size(),actlength=length/2;int returnme=INT_MIN;
        for(int i=0;i<actlength;i++){
            returnme=max(returnme,a[i]+a[length-i-1]);
        }
        return returnme;
    }
};