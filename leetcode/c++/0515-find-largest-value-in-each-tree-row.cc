// https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// Medium
// Mock

#include<vector>

using namespace std;

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
    void largestValuesRec(TreeNode* root, int height, vector<int>& ret) {
        if (!root) return;
        if (height+1 > ret.size()) {
            ret.push_back(INT_MIN);
        }
        if (root->val > ret[height]) {
            ret[height] = root->val;
        }
        largestValuesRec(root->left, height+1, ret);
        largestValuesRec(root->right, height+1, ret);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        largestValuesRec(root, 0, ret);
    }
};