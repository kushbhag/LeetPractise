// https://leetcode.com/problems/merge-k-sorted-lists/
// Hard

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
#include<vector>
#include<queue>
using namespace std;

struct myComp { 
    constexpr bool operator()( 
        pair<int, int> const& a, 
        pair<int, int> const& b) 
        const noexcept 
    { 
        return a.first > b.first; 
    } 
};

class Solution {

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * sortedList = nullptr;
        ListNode * head = nullptr;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
        int size = lists.size();
        for (int i = 0; i < size; ++i) {
            if(lists[i]) pq.push({lists[i]->val, i});
        }
        pair<int, int> curr;
        while (!pq.empty()) {
            curr = pq.top();
            pq.pop();
            if (sortedList) {
                sortedList->next = lists[curr.second];
                sortedList = sortedList->next;
            } else {
                sortedList = lists[curr.second];
                head = sortedList;
            }
            if (lists[curr.second] && lists[curr.second]->next) {
                lists[curr.second] = lists[curr.second]->next;
                pq.push({lists[curr.second]->val, curr.second});
            }
        }
        return head;
    }
};