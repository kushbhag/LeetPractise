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
    int ret;
    // If k == 0 then return true
    bool kthSmallestRec(TreeNode* root, int& k) {
        if (!root) return false;
        if (kthSmallestRec(root->left, k)) return true;
        --k;
        if (k == 0) {
            ret = root->val;
            return true;
        }
        return kthSmallestRec(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int& k) {
        kthSmallestRec(root, k);
        return ret;
    }
};