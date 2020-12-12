// https://leetcode.com/problems/add-two-numbers/
// Medium

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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ret = head;
        int carry = 0;
        while (1) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (sum >= 10) {
                head->val = sum - 10;
                carry = 1;
            } else {
                head->val = sum;
                carry = 0;
            }
            if(l1 || l2) {
                head->next = new ListNode(0);
                head = head->next;
            } else {
                break;
            }
        }
        if (carry == 1) {
            head->next = new ListNode(1);
        }
        return ret;
    }
};