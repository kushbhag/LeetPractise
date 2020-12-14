// https://leetcode.com/problems/palindrome-linked-list/
// Easy

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
    int size = 0;
public:
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr) {
            ++size;
            curr = curr->next;
        }
        curr = head;
        ListNode* other = head->next;
        ListNode* temp = nullptr;
        curr->next = nullptr;
        for (int i = 0; i < size/2; ++i) {
            temp = other->next;
            other->next = curr;
            curr = other;
            other = temp;
        }
        for (int i = 0; i < size/2; ++i) {
            if(curr->val != head->val) return false;
            curr = curr->next;
            head = head->next;
        }
        return true;
    }
};