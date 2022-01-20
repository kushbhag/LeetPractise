// https://leetcode.com/problems/reverse-linked-list-ii/
// Medium
// June 23rd, 2021 Challenge

/**
Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 1;
        ListNode* curr = head, *lNode = head, *l = head, *r = nullptr, *first = head;
        while (curr != nullptr) {
            if (i == left-1) {
                lNode = curr;
                curr = curr->next;
                l = curr;
                first = curr;
            } else if (i >= left && i <= right) {
                curr = curr->next;
                l->next = r;
                r = l;
                l = curr;
                if (i == right) {
                    lNode->next = r;
                    first->next = l;
                    return first == head ? r : head;
                }
            } else {
                curr =  curr->next;
            }
            i++;
        }
        return head;
    }
};