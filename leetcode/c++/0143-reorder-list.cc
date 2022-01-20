// https://leetcode.com/problems/reorder-list/
// Medium
// Mock

#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        vector<ListNode*> v;
        ListNode* tempHead = head;
        int count = 0;
        while (tempHead != nullptr) {
            v.push_back(tempHead);
            tempHead = tempHead->next;
            ++count;
        }
        ListNode* next = head->next;
        ListNode* temp = nullptr;
        for (int i = 0; i < count/2; ++i) {
            temp = v.back();
            v.pop_back();
            head->next = temp;
            if (temp == next) {
                temp->next = nullptr;
                return;
            }
            temp->next = next;
            head = next;
            next = head->next;
        }
        head->next = nullptr;
        return;
    }
};