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
        int difference = 0 ;
        ListNode* headFirst = headA;
        ListNode* headSecond = headB;
        while (headA->next || headB->next) {
            if (headA->next == nullptr) {
                ++difference;
                headB = headB->next;
            } else if (headB->next == nullptr) {
                --difference;
                headA = headA->next;
            } else if (headA == headB) {
                return headA;
            } else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        if (headA != headB) {
            return nullptr;
        }
        if (difference < 0) {
            ListNode* temp = headFirst;
            headFirst = headSecond;
            headSecond = temp;
            difference *= -1;
        }
        for (int i = 0; i < difference; ++i) {
            headSecond = headSecond->next;
        }
        while (headFirst && headSecond) {
            if (headFirst == headSecond) return headFirst;
            headFirst = headFirst->next;
            headSecond = headSecond->next;
        }
        return headSecond;
    }
};