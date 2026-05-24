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
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        int mid = cnt/2 + 1;
        cnt = 0;
        temp = head;
        while (temp != nullptr) {
            cnt++;
            if (cnt == mid) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};