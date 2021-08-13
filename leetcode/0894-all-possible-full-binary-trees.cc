// https://leetcode.com/problems/all-possible-full-binary-trees/
// Medium

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
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> ret (n+1);
        if (n % 2 == 0) return {};
        ret[1].push_back(new TreeNode(0));
        if (n == 1) return ret[1];
        ret[3].push_back(new TreeNode(0, new TreeNode(0), new TreeNode(0)));
        if (n == 3) return ret[3];
        
        for (int i = 5; i <= n; i += 2) {
            for (int j = 1; j < i; j += 2) {
                //cout << i-j-1 << ' ' << j << endl;
                for (TreeNode* left: ret[i-j-1]) {
                    for (TreeNode* right: ret[j]) {
                        TreeNode* t = new TreeNode(0);
                        t->left = left;
                        t->right = right;
                        ret[i].push_back(t);
                    }
                }
            }
        }
        return ret[n];

    }
};