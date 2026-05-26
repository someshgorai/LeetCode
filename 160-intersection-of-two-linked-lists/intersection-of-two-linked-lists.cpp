/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* head1 = headA;
        ListNode* head2 = headB;
        bool switch1 = true, switch2 = true;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1 == head2) return head1;
            head1 = head1->next;
            head2 = head2->next;
            if (!head1 && switch1) {
                head1 = headB;
                switch1 = false;
            }
            if (!head2 && switch2) {
                head2 = headA;
                switch2 = false;
            }
        }
        
        return nullptr;
    }
};