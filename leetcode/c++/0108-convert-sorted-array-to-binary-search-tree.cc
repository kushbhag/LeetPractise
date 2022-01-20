// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Easy

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
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int lo, int hi) {
        if (lo > hi) return nullptr;
        int mid = (lo + hi) / 2;
        TreeNode* ret = new TreeNode(nums[mid]);
        ret->left = sortedArrayToBSTHelper(nums, lo, mid-1);
        ret->right = sortedArrayToBSTHelper(nums, mid+1, hi);
        return ret;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size()-1);
    }
};