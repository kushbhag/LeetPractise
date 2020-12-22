// https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow && fast) {
            if (slow == fast) return true;
            if (fast->next && fast->next->next) {
                fast = fast->next->next;
            } else {
                return false;
            }
            slow = slow->next;
        }
        return false;
    }
};