// https://leetcode.com/problems/balanced-binary-tree/
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
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int heightOfTree(TreeNode* root) {
        if (!root) return 0;
        int left = heightOfTree(root->left);
        //if (left == -2) return -2;
        int right = heightOfTree(root->right);
        if (right == -2 || left == -2 || abs(left - right) > 1) return -2;
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (heightOfTree(root) == -2) return false;
        return true;
    }
};