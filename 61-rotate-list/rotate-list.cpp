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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k) return head;
        ListNode* temp = head;
        int cnt = 0;

        while (temp) {
            cnt++;
            temp = temp->next;
        }

        int rot = k % cnt;

        temp = head;
        while (rot) {
            rot--;
            temp = temp->next;
        }

        ListNode* end = head;
        while (temp->next) {
            end = end->next;
            temp = temp->next;
        }

        temp->next = head;
        head = end->next;
        end->next = nullptr;

        return head;
    }
};