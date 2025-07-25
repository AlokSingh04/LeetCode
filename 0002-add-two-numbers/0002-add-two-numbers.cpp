class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode temp(0);
        ListNode* node = &temp;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            node->next = new ListNode(sum % 10);
            carry = sum / 10;
            node = node->next;
        }

        return temp.next;
    }
};
