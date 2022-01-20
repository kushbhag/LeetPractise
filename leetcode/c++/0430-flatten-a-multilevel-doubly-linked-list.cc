// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Medium

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
    Node* flattenBack(Node* head) {
        Node *currHead = head;
        while (currHead->next) {
            Node* n = currHead->next;
            if (currHead->child) {
                Node* back = flattenBack(currHead->child);
                back->next = n;
                currHead->child->prev = currHead;
                currHead->next = currHead->child;
                currHead->child = nullptr;
                n->prev = back;
            }
            currHead = currHead->next;
        }
        if (currHead->child) {
            Node* back = flattenBack(currHead->child);
            currHead->child->prev = currHead;
            currHead->next = currHead->child;
            currHead->child = nullptr;
            return back;
        }
        return currHead;
    }
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        Node *currHead = head;
        flattenBack(head);
        return head;
    }
};