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
    int returnLength(ListNode* head){
        
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;


    }
    ListNode* deleteMiddle(ListNode* head) {
        
        int len = returnLength(head);
        if(len<=1) return nullptr;


        int rem = len/2;
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            if(count==rem){
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }

        return head;


    }
};