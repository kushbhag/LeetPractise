// https://leetcode.com/problems/binary-tree-inorder-traversal/
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
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SolutionIteratively {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        vector<TreeNode*> stack;
        stack.push_back(root);
        while (!stack.empty()) {
            TreeNode* curr = stack.back();
            stack.pop_back();
            if (curr) {
                if (curr->left) {
                    stack.push_back(curr);
                    stack.push_back(curr->left);
                    curr->left = nullptr;
                    continue;
                }
                ret.push_back(curr->val);
                stack.push_back(curr->right);
            }
        }
        return ret;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorderTraversalRec(root, v);
        return v;
    }

    void inorderTraversalRec(TreeNode* root, vector<int>& v) {
        if (root) {
            inorderTraversalRec(root->left, v);
            v.push_back(root->val);
            inorderTraversalRec(root->right, v);
        }
    }
};