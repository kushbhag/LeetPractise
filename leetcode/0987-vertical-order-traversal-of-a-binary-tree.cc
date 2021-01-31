// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Hard

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
#include<map>
#include<set>
#include<vector>

using namespace std;

class Solution {
    map<int, map<int, multiset<int>>> m;
    int minX = 0;
    int maxX = 0;
    void traverse(TreeNode* root, int x, int y) {
        if (!root) return;
        m[y][x].insert(root->val);
        minX = min(x, minX);
        maxX = max(x, maxX);
        traverse(root->left, x-1, y+1);
        traverse(root->right, x+1, y+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        if (!root) return v;
        traverse(root, 0, 0);
        for (int i = minX; i <= maxX; ++i) {
            v.push_back(vector<int> ());
        }
        for (pair<int, map<int, multiset<int>>> mm: m) {
            for (pair<int, multiset<int>> n: mm.second) {
                for (int x: n.second) {
                    v[n.first-minX].push_back(x);
                }
            }
        }
        return v;
    }
};