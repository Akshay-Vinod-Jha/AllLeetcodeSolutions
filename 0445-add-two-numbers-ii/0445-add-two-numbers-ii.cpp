class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> one, two;

        while (l1) {
            one.push(l1->val);
            l1 = l1->next;
        }

        while (l2) {
            two.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* last = nullptr;

        while (!one.empty() || !two.empty()) {
            int first = 0, second = 0;

            if (!one.empty()) {
                first = one.top();
                one.pop();
            }

            if (!two.empty()) {
                second = two.top();
                two.pop();
            }

            int sum = first + second + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode* newn = new ListNode(sum);
            newn->next = last;
            last = newn;
        }

        if (carry) {
            ListNode* head = new ListNode(carry);
            head->next = last;
            return head;
        }

        return last;
    }
};
