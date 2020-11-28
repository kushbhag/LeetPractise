#include<vector>
using namespace std;
/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

https://leetcode.com/problems/leaf-similar-trees/
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
    void generateLeaf(TreeNode * root, vector<int>& leafs){
        if (root->left == nullptr && root->right == nullptr){
            leafs.push_back(root->val);
            return;
        }
        generateLeaf(root->left, leafs);
        generateLeaf(root->right, leafs);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        generateLeaf(root1, leaf1);
        vector<int> leaf2;
        generateLeaf(root2, leaf2);
        if (leaf1.size() != leaf2.size()) return false;
        for (int i = 0; i < leaf1.size(); i ++){
            if (leaf1[i] != leaf2[i]) return false;
        }
        return true;
    }
};

int main(){

}