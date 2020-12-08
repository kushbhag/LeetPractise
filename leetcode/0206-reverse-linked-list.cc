// https://leetcode.com/problems/reverse-linked-list/
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
public:
    ListNode* reverseList(ListNode* head) {
        // Solution 1
        ListNode* curr = nullptr;
        while (head) {
            ListNode* temp = head;
            head = head->next;
            temp->next = curr;
            curr = temp;
        }
        return curr;

        // Solution 2
        if (!head) return nullptr;
        ListNode* other = head->next;
        head->next = nullptr;
        while (other != nullptr) {
            ListNode* temp = other->next;
            other->next = head;
            head = other;
            other = temp;
        }
        return head;
    }
};