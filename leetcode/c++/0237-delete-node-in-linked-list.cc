// https://leetcode.com/problems/delete-node-in-a-linked-list/
// Easy

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node->next->next != nullptr) {
            node->val = node->next->val;
            node = node->next;
        }
        delete node->next;
        node->next = nullptr;
    }
};
