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
    void reorderList(ListNode* head) {
        if (!head || !(head->next) || !(head->next->next)) return;
        ListNode* node = head;
        stack<ListNode*> st;

        while (node) {
            st.push(node);
            node = node->next;
        }

        ListNode* curr  = head;
        ListNode* front = head->next;

        while (curr != st.top() && front != st.top()) {
            ListNode* last = st.top();
            st.pop();

            curr->next = last;
            last->next = front;
            curr       = front;
            front      = front->next;
        }
        if (front == st.top()) front->next = nullptr;
        if (curr == st.top()) curr->next = nullptr;
    }
};