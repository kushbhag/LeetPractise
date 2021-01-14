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

#include<algorithm>
using namespace std;

class Solution {
    void lengthOfList(ListNode* l1, int& len) {
        if (!l1) return;
        lengthOfList(l1->next, ++len);
    }
    int remainderList(ListNode* l1) {
        if (!l1) return 0;
        //cout << l1->val << endl;
        int rem = remainderList(l1->next);
        l1->val += rem == 1 ? 1 : 0;
        
        if (l1->val >= 10) {
            l1->val -= 10;
            return 1;
        }
        return 0;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        lengthOfList(l1, len1);
        lengthOfList(l2, len2);
        ListNode* main = l1, *side = l2;;
        if (len1 < len2) {
            swap(main, side);
            swap(len1, len2);
        }
        //cout << len1 << ' ' << len2 << endl;
        ListNode*ret = main;
        while (len2 < len1) {
            main = main->next;
            --len1;
        }
        for (int i = 0; i < len1; ++i) {
            main->val += side->val;
            //cout << main->val << endl;
            main = main->next;
            side = side->next;
        }
        int rem = remainderList(ret);
        if (rem == 1) {
            ListNode* t = new ListNode(1, ret);
            return t;
        }
        return ret;
    }
};