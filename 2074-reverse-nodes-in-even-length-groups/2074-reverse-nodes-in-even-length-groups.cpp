class Solution {
public:
    vector<int> toarray(ListNode* head){
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        return v;
    }
    ListNode* returnLinkedList(vector<int>& a){
        ListNode* head = new ListNode(a[0]);
        ListNode* curr = head;
        for(int i = 1; i < a.size(); i++){
            curr->next = new ListNode(a[i]);
            curr = curr->next;
        }
        return head;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int> a = toarray(head);
        int n = a.size();
        int group = 1;
        int i = 0;
        while(i < n){
            int start = i;
            int end = min(i + group - 1, n - 1);
            int len = end - start + 1;
            if(len % 2 == 0){
                reverse(a.begin() + start, a.begin() + end + 1);
            }
            i += group;
            group++;
        }
        return returnLinkedList(a);
    }
};
