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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (ListNode* node : lists) {
            if (node) pq.push(node);
        }
        
        ListNode* prehead = new ListNode();
        ListNode* current = prehead;
        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            current->next = node;
            current = node;
            if(node->next) pq.push(node->next);
        }
        return prehead->next;
    }
};