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
        Node* curr = head;
        unordered_map<Node*, Node*> mpp;

        while (curr) {
            Node* copy = new Node (curr->val);
            mpp[curr] = copy;
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            Node* copy = mpp[curr];
            copy->next = mpp[curr->next];
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            Node* copy = mpp[curr];
            copy->random = mpp[curr->random];
            curr = curr->next;
        }

        return mpp[head];
    }
};