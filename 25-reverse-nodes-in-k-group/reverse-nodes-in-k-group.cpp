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
    void reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* front = head->next;
            head->next = prev;
            prev = head;
            head = front;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 0) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* start = dummy;
        ListNode* end = head;

        while (start) {
            end = start->next;
            int cnt = 1;
            while (end && cnt < k) {
                cnt++;
                end = end->next;
            }
            if (end) {
                ListNode* front = end->next;
                ListNode* rev = start->next;
                end->next = nullptr;
                start->next = nullptr;
                reverse(rev);
                start->next = end;
                rev->next = front;
                if (start == dummy) head = end;
                start = rev;
            }
            else break;
        }
        delete dummy;
        return head;
    }
};