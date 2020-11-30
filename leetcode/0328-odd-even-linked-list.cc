// https://leetcode.com/problems/odd-even-linked-list/
// Medium

struct ListNode {
    int val;
    ListNode *next;
};

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        bool odd = true;
        ListNode* headEven = head->next, *a = head, *b = head->next;
        while(b && b->next) {
            odd = !odd;
            a->next = b->next;
            a = b;
            b = b->next;
        }
        if (odd) {
            a->next = headEven;
        } else {
            b->next = headEven;
            a->next = nullptr;
        }
        return head;
    }
};