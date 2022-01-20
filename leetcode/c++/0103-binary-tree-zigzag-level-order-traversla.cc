// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
    void levelOrderRec(TreeNode* root, vector<vector<int>>& ret, int level) {
        if (!root) return;
        if (ret.size() <= level) {
            ret.push_back(vector<int> {root->val});
        } else {
            ret[level].push_back(root->val);
        }
        if (level % 2 != 0) {
            levelOrderRec(root->left, ret, level + 1);
            levelOrderRec(root->right, ret, level + 1);
        } else {
            levelOrderRec(root->right, ret, level + 1);
            levelOrderRec(root->left, ret, level + 1);
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        unordered_map<int, int> sizeOfLevel;
        sizeOfLevel[0] = 1;
        deque<pair<TreeNode*, int>> q;
        q.push_back(pair<TreeNode*, int> (root, 0));
        int currLevel = 0;
        while (!q.empty()) {
            pair<TreeNode*, int> temp;
            if (currLevel % 2 != 0) {
                temp = q.front();
                // if (temp.first) cout << "FRONT: " << temp.first->val << endl;

                q.pop_front();
                
            } else {
                temp = q.back();
                // if (temp.first) cout << "BACK: " << temp.first->val << endl;;
                q.pop_back();
                
            }
            --sizeOfLevel[currLevel];
            if (sizeOfLevel[currLevel] <= 0) {
                currLevel++;
            }
            if (!temp.first) continue;
            if (ret.size() <= temp.second) {
                ret.push_back(vector<int> {temp.first->val});
            } else {
                ret[temp.second].push_back(temp.first->val);
            }
            if (temp.second % 2 != 0) {
                q.push_back(pair<TreeNode*, int> (temp.first->right, temp.second+1));
                q.push_back(pair<TreeNode*, int> (temp.first->left, temp.second+1));
            } else {
                q.push_front(pair<TreeNode*, int> (temp.first->left, temp.second+1));
                q.push_front(pair<TreeNode*, int> (temp.first->right, temp.second+1));
            }
            sizeOfLevel[temp.second+1] += 2;
            
            // for (pair<TreeNode*, int> n: q) {
            //     if (n.first) cout << n.first->val << ' ';
            // }
            // cout << endl;
        }
        return ret;
    }
};