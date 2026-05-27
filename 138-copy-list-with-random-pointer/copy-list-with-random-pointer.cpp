/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;

        while (curr) {
            Node* copy = new Node(curr->val);
            Node* front = curr->next;

            curr->next = copy;
            copy->next = front;
            curr = curr->next->next;
        }

        curr = head;
        while (curr) {
            Node* copy = curr->next;
            Node* rand = curr->random;

            if (rand) copy->random = rand->next;
            else copy->random = nullptr;

            curr = curr->next->next;
        }

        curr = head;
        Node* dummy = new Node(0);
        dummy->next = curr->next;
        while (curr) {
            Node* copy  = curr->next;
            Node* front = copy->next;

            curr->next = front;
            if (front) copy->next = front->next;
            curr = front;
        }

        Node* copyHead = dummy->next;
        delete dummy;
        return copyHead;
    }
};