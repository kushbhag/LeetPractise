// https://leetcode.com/problems/intersection-of-two-linked-lists/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 1, len2 = 1;
        if (!headA || !headB) return nullptr;
        ListNode* tempHeadA = headA;
        ListNode* tempHeadB = headB;
        while (headA->next || headB->next) {
            if (headA->next) {
                ++len1;
                headA = headA->next;
            }
            if (headB->next) {
                ++len2;
                headB = headB->next;
            }
        }
        if (headA != headB) {
            return nullptr;
        }
        while(len1 > len2) {
            tempHeadA = tempHeadA->next;
            --len1;
        }
        while(len2 > len1) {
            tempHeadB = tempHeadB->next;
            --len2;
        }

        for (int i = 0; i < len1; ++i) {
            if (tempHeadA == tempHeadB) return tempHeadB;
            tempHeadB = tempHeadB->next;
            tempHeadA = tempHeadA->next;
        }
        return nullptr;
    }
};