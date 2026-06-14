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
    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;

        while (curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* temp2 = reverse(slow);
        ListNode* temp1 = head;

        int maxTwinSum = 0;
        while (temp1 && temp2) {
            maxTwinSum = max(maxTwinSum, temp1->val+ temp2->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        reverse(slow);

        return maxTwinSum;
    }
};