// https://leetcode.com/problems/validate-binary-search-tree/
// Medium


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

// Solution is better cause you can simply just do an inorder traversal
class SlowerSolution {
    void inorderTraversal(TreeNode* root, vector<int>& v) {
        if (root) {
            inorderTraversal(root->left, v);
            v.push_back(root->val);
            inorderTraversal(root->right, v);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorderTraversal(root, v);
        for (int i = 0; i < v.size() - 1; ++i) {
            if (v[i] >= v[i+1]) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
    bool isValidBSTRec(TreeNode* root, int& min, int& max) {
        if (root) {
            min = root->val < min ? root->val : min;
            max = root->val > max ? root->val : max;
            
            if (root->left) {
                int tempMax = INT_MIN;
                bool test = isValidBSTRec(root->left, min, tempMax);
                if (!test || tempMax >= root->val) {
                    return false;
                }
                // cout << root->val << ' ' << min << ' ' << max << endl;
            }
            if (root->right) {
                int tempMin = INT_MAX;
                bool test = isValidBSTRec(root->right, tempMin, max);
                // cout << root->val << ' ' << min << ' ' << max << endl;
                if (!test || tempMin <= root->val) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        int min = INT_MAX;
        int max = INT_MIN;
        return isValidBSTRec(root, min, max);
    }
};