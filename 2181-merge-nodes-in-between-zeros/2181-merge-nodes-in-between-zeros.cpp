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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> answer;
        int ans=0;
        ListNode* dummy=head;dummy=dummy->next;
        while(dummy!=nullptr){
            if(dummy->val==0){
                answer.push_back(ans);
                ans=0;
            }else{
                ans+=dummy->val;
            }
            dummy=dummy->next;
        }
        int length=answer.size();
        ListNode* returnme=new ListNode(answer[0]);ListNode* rd=returnme;
        for(int i=1;i<length;i++){
            rd->next=new ListNode(answer[i]);rd=rd->next;
        }
        return returnme;
    }
};