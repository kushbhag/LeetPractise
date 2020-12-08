// https://leetcode.com/problems/binary-tree-level-order-traversal/
// Medium

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

class Solution {
    void levelOrderRec(TreeNode* root, vector<vector<int>>& ret, int level) {
        if (!root) return;
        if (ret.size() <= level) {
            ret.push_back(vector<int> {root->val});
        } else {
            ret[level].push_back(root->val);
        }
        levelOrderRec(root->left, ret, level + 1);
        levelOrderRec(root->right, ret, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        levelOrderRec(root, v, 0);
        return v;
    }
};