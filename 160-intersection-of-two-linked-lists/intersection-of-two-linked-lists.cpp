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

        while (head1 != nullptr && head2 != nullptr) {
            if (head1 == head2) return head1;
            head1 = head1->next;
            head2 = head2->next;
        }

        if (head1 == head2) return nullptr;

        if (head1 == nullptr) {
            head1 = headB;
            while (head2 != nullptr) {
                head2 = head2->next;
                head1 = head1->next;
            }
            head2 = headA;
        }
        else {
            head2 = headA;
            while (head1 != nullptr) {
                head2 = head2->next;
                head1 = head1->next;
            }
            head1 = headB;
        }

        while (head1 != nullptr && head2 != nullptr) {
            if (head1 == head2) return head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        
        return nullptr;
    }
};