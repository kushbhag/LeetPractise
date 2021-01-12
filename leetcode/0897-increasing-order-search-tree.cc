// https://leetcode.com/problems/increasing-order-search-tree/
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

class Solution {
    void increasingBSTRec(TreeNode* root, vector<int> &v) {
        if (!root->left && !root->right) {
            v.push_back(root->val);
        } else if (!root->right) {
            increasingBSTRec(root->left, v);
            v.push_back(root->val);
        } else if (!root->left) {
            v.push_back(root->val);
            increasingBSTRec(root->right, v);
        } else {
            increasingBSTRec(root->left, v);
            v.push_back(root->val);
            increasingBSTRec(root->right, v);
        }
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return nullptr;
        vector<int> v;
        increasingBSTRec(root, v);
        TreeNode* curr = new TreeNode(v[0]);
        TreeNode * temp = curr;
        for (int i = 1; i < v.size(); ++i) {
            curr->right = new TreeNode(v[i]);
            curr = curr->right;
        }
        return temp;
    }
};