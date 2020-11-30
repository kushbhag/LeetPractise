// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int& k) {
        int x = 0;
        if (k == 1 && root->left == nullptr) {
            k = 0;
            return root->val;
        } else if (root->left == nullptr && root->right == nullptr) {
            k--;
            return root->val;
        }
        if (root->left) {
            x = kthSmallest(root->left, k);
            if (k == 0) {
                return x;
            }
        }
        if (k == 1) {
            k = 0;
            return root->val;
        }
        k --;
        if (root->right) {
            x = kthSmallest(root->right, k);
            if (k == 0) {
                return x;
            }
        }
        return x;
    }
};