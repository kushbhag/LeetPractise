// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include<vector>
#include<queue>

using namespace std;

class Solution {
    void inOrder(TreeNode* root, vector<int>& mem) {
        if (root->left) {
            inOrder(root->left, mem);
        }
        mem.push_back(root->val);
        if (root->right) {
            inOrder(root->right, mem);
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        if (root) inOrder(root, inorder);
        else return false;

        int low = 0, high = inorder.size() - 1;
        while(low < high) {
            if (inorder[low] + inorder[high] == k) {
                return true;
            } else if (inorder[low] + inorder[high] > k) {
                --high;
            } else {
                ++low;
            }
        }
        return false;
    }
};