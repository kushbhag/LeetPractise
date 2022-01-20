// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Medium
// June 30th, 2021 Challenge

/**
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include<vector>

using namespace std;

class Solution {
    bool parseFind(TreeNode* root, vector<TreeNode*>& v, int find) {
        if (root == NULL) return false;
        if (root->val == find ||
            parseFind(root->left, v, find) ||
            parseFind(root->right, v, find)) {
            v.push_back(root);
            return true;
        }
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1, v2;
        parseFind(root, v1, p->val);
        parseFind(root, v2, q->val);
        int size1 = v1.size()-1, size2 = v2.size()-1;
        TreeNode* curr = root;
        for (; size1 >= 0 && size2 >= 0; --size1, --size2) {
            if (v1[size1]->val != v2[size2]->val) {
                break;
            } else {
                curr = v1[size1];
            }
        }
        return curr;
    }
};