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
    void rightSideViewRec(TreeNode* root, int depth, vector<int>& v) {
        if (!root) return;
        if (depth >= v.size()) {
            v.push_back(root->val);
        }
        rightSideViewRec(root->right, depth+1, v);
        rightSideViewRec(root->left, depth+1, v);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        rightSideViewRec(root, 0, v);
        return v;
    }
};