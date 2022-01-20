// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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

class Solution {
    TreeNode* flattenRec(TreeNode* root) {
        if (!root->left && !root->right) return root;
        if (!root->left) {
            return flattenRec(root->right);
        }
        TreeNode* lastLeft = flattenRec(root->left);
        if (!root->right) {
            root->right = root->left;
            root->left = nullptr;
            return lastLeft;
        }
        TreeNode* lastRight = flattenRec(root->right);
        lastLeft->right = root->right;
        root->right = root->left;
        root->left = nullptr;
        return lastRight;
    }
public:
    void flatten(TreeNode* root) {
        if (root) {
            flattenRec(root);
        }
    }
};