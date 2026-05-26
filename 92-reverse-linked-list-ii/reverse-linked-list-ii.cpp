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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || head->next == nullptr || left == right) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = head;
        ListNode* prev = dummy;
        ListNode* front = head->next;

        int cnt = 1;
        while (curr && cnt != left) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        front = curr->next;
        while (front && cnt != right) {
            curr->next = front->next;
            front->next = prev->next;
            prev->next = front;
            cnt++;
            front = curr->next;
        }

        return dummy->next;
    }
};