// https://leetcode.com/problems/linked-list-cycle-ii/
// Medium

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (slow && fast) {
            if (fast->next && fast->next->next) {
                fast = fast->next->next;
            } else {
                return nullptr;
            }
            slow = slow->next;

            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};