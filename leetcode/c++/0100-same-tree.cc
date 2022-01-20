// https://leetcode.com/problems/same-tree/
// Easy

/**
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<vector>

using namespace std;

class IterativeSolution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<pair<TreeNode*, TreeNode*>> stack;
        stack.push_back({p, q});
        while (!stack.empty()) {
            pair<TreeNode*, TreeNode*> tp = stack.back();
            stack.pop_back();
            if (!tp.first && !tp.second) continue;
            if (!tp.first || !tp.second) return false;
            if (tp.first->val != tp.second->val) return false;
            stack.push_back({tp.first->left, tp.second->left});
            stack.push_back({tp.first->right, tp.second->right});
        }
        return true;
    }
};


class RecursiveSolution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if ((!p && q) || (p && !q) || (p->val != q->val)) return false;
        if (!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right)) return false;
        return true;
    }
};