// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Medium
// June 8th, 2021 Challenge

#include<vector>
#include<unordered_set>
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
    unordered_set<int> s;
    int pre = 0, in = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (in >= preorder.size() || pre >= preorder.size()) return nullptr;
        if (s.find(inorder[in]) != s.end()) return nullptr;
        TreeNode* curr = new TreeNode(preorder[pre]);
        s.insert(preorder[pre]);
        if (preorder[pre] == inorder[in]) {
            ++pre;
            ++in;
            curr->right = buildTree(preorder, inorder);
            return curr;
        }
        pre++;
        curr->left = buildTree(preorder, inorder);
        in++;
        curr->right = buildTree(preorder, inorder);
        return curr;
    }
};