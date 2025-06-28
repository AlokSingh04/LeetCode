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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* p = head;
        while(p){
            size++;
            p = p->next;
        }

        int removeIndex = size - n;
        if(removeIndex == 0){
            return head->next;
        }

        p = head;
        for(int i=0;i<size-1;i++){
            if(i+1 == removeIndex){
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return head;
    }
};