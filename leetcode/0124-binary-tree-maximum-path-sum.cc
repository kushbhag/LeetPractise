// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Hard

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
    int maxSoFar = 0;
    int maxPathSumRec(TreeNode* root) {
        int left = 0, right = 0;
        if (root->left) {
            left = maxPathSumRec(root->left);
        }
        if (root->right) {
            right = maxPathSumRec(root->right);
        }
        maxSoFar = max(max(root->val, maxSoFar), max(root->val + left, max(root->val + right, root->val + left + right)));
        return max (left+root->val, max(root->val, right+root->val));
    }
public:
    int maxPathSum(TreeNode* root) {
        maxSoFar = root->val;
        maxPathSumRec(root);
        return maxSoFar;
    }
};