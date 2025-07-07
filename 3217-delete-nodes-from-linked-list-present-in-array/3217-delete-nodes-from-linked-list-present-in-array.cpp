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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        
        unordered_set<int> set;
        for(int i : nums){
            set.insert(i);
        }

        ListNode* p = &dummy;
        while(p->next){
            bool flag = 0;

            if(set.find(p->next->val) != set.end()){
                flag = 1;
            }
            
            if(flag){
                p->next = p->next->next;
            }else{
                p = p->next;
            }
        }
        return dummy.next;
    }
};