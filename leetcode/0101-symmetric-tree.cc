// https://leetcode.com/problems/symmetric-tree/
// Easy

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
#include<deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> queue;
        if (root == nullptr) return true;
        queue.push_back(root->left);
        queue.push_back(root->right);
        TreeNode* a;
        TreeNode* b;
        while (!queue.empty()) {
            a = queue.front();
            queue.pop_front();
            b = queue.front();
            queue.pop_front();
            if ((a == nullptr && b != nullptr) || 
                (a != nullptr && b == nullptr)) {
                return false;
            } else if (a && b) {
                if (a->val == b->val) {
                    queue.push_back(a->left);
                    queue.push_back(b->right);
                    queue.push_back(a->right);
                    queue.push_back(b->left);
                } else {
                    return false;
                }  
            }
        }
        return true;
    }
};