// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<vector>

using namespace std;

class Solution {
    int ret;
    vector<int> countPairsRec(TreeNode* root, int distance) {
        if (root->left == nullptr && root->right == nullptr) {
            vector<int> v = vector<int> (distance+1, 0);
            v[1] = 1;
            return v;
        }
        
        if (!root->left) {
            vector<int> v = countPairsRec(root->right, distance);
            for (int i = distance; i >= 2; --i) {
                v[i] = v[i-1];
            }
            v[1] = 0;
            return v;
        }
        if (!root->right) {
            vector<int> v = countPairsRec(root->left, distance);
            for (int i = distance; i >= 2; --i) {
                v[i] = v[i-1];
            }
            v[1] = 0;
            return v;
        }
        vector<int> left = countPairsRec(root->left, distance);
        vector<int> right = countPairsRec(root->right, distance);
        vector<int> v = vector<int> (distance+1, 0);
        for (int i = 1; i <= distance; ++i) {
            for (int j = 1; j <= distance; ++j) {
                if (i + j <= distance) {
                    ret += left[i] * right[j];
                }
            }
        }
        for (int i = 1; i < distance; ++i) {
            v[i+1] = left[i] + right[i];
        }
        return v;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        vector<int> v = countPairsRec(root, distance);
        return ret;
    }
};