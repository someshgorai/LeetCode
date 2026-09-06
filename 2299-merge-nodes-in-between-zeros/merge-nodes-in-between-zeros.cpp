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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* travs = dummy;
        ListNode* node  = head;
        int sum = 0;

        while (node) {
            if (node->val == 0 && sum != 0) {
                ListNode* temp = new ListNode(sum);
                travs->next = temp;
                travs = temp;
                sum = 0;
            }
            else sum += node->val;
            node = node->next;
        }

        return dummy->next;
    }
};