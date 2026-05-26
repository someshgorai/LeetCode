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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;

        ListNode* sumHead = new ListNode();  
        ListNode* ans = sumHead;

        int carry = 0;

        while (head1 != nullptr || head2 != nullptr || carry != 0) {
            int v1 = (head1 != nullptr) ? head1->val : 0;
            int v2 = (head2 != nullptr) ? head2->val : 0;

            int sum = v1 + v2 + carry;
            carry = sum / 10;

            ans->next = new ListNode(sum % 10);
            ans = ans->next; 

            if (head1 != nullptr) head1 = head1->next;
            if (head2 != nullptr) head2 = head2->next;
        }

        return sumHead->next; 
    }
};
