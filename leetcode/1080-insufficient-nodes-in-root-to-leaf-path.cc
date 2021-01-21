// https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
// Medium
// Mock

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
int limit;
    int sufficientSubsetRec(TreeNode* root, int currSum) {
        if (!root->left && !root->right) {
            currSum += root->val;
            return currSum;
        } else if (!root->right) {
            int total = sufficientSubsetRec(root->left, currSum + root->val);
            if (total < limit) {
                root->left = nullptr;
            }
            return total;
        } else if (!root->left) {
            int total = sufficientSubsetRec(root->right, currSum + root->val);
            if (total < limit) {
                root->right = nullptr;
            }
            return total;
        } else {
            int totalLeft = sufficientSubsetRec(root->left, currSum + root->val);
            int totalRight = sufficientSubsetRec(root->right, currSum + root->val);
            if (totalLeft < limit) {
                root->left = nullptr;
            }
            if (totalRight < limit) {
                root->right = nullptr;
            }
            return max(totalLeft, totalRight);
        }
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root) return nullptr;
        this->limit = limit;
        int total = sufficientSubsetRec(root, 0);
        return total < limit ? nullptr : root;
    }
};