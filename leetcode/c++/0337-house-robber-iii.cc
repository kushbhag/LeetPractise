/**
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */
#include<utility>
#include<unordered_map>
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
    unordered_map<TreeNode*, int> mSkip;
    unordered_map<TreeNode*, int> mNonSkip;
    int robRec(TreeNode* root, bool skip) {
        if (root == nullptr) return 0;
        int left, right;
        if (skip) {
            if (mSkip.find(root) != mSkip.end()) return mSkip[root];
            left = max(robRec(root->left, true), robRec(root->left, false));
            right = max(robRec(root->right, true), robRec(root->right, false));
            mSkip[root] = left+right;
        } else {
            if (mNonSkip.find(root) != mNonSkip.end()) return mNonSkip[root];
            left = robRec(root->left, true);
            right = robRec(root->right, true);
            left += root->val;
            mNonSkip[root] = left+right;
        }
        return left + right;
    }
public:
    int rob(TreeNode* root) {
        return max(robRec(root, false), robRec(root, true));
    }
};