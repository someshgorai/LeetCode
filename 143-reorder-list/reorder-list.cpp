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
private:
    void reverseLinks(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* front = head->next;
            head->next = prev;
            prev = head;
            head = front;
        }
    }
public:
    void reorderList(ListNode* head) {
        if (!head || !(head->next) || !(head->next->next)) return;

        ListNode* slow  = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* first = head;
        ListNode* second;
        if (fast->next) {
            fast = fast->next;
        }
        second = fast;

        reverseLinks(slow->next);
        slow->next = nullptr;
        
        while(second != nullptr){

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};