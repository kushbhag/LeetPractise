// https://leetcode.com/problems/reverse-nodes-in-k-group/
// Hard
// July 18th, 2021 Challenge


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* newHead = nullptr;
    ListNode* retHead = nullptr;
    ListNode* reverseKGroupDone(ListNode *head, int k) {
        if (head == nullptr || k == 1) {
            retHead = head;
            return head;
        }
        ListNode* last = reverseKGroupDone(head->next, k-1);
        if (last == nullptr) {
            return last;
        } else {
            head->next = last->next;
            last->next = head;
        }
        return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        while(head != nullptr) {
            ListNode* last = nullptr;
            if (newHead == nullptr) {
                last = reverseKGroupDone(head, k);
                newHead = retHead;
            } else {
                last = reverseKGroupDone(head->next, k);
                if (last) {
                    head->next = retHead;
                }   
            }
            head = last;
        }
        return newHead;
    }
};