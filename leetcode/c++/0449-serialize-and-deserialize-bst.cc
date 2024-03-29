// https://leetcode.com/problems/serialize-and-deserialize-bst/
// Medium

#include<string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N ";
        string s = "";
        s += to_string(root->val) + " ";
        string left = serialize(root->left);
        string right = serialize(root->right);
        s += left;
        s += right;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss (data);
        return dese(ss);
    }
    
    TreeNode* dese(stringstream& ss) {
        int found;
        string temp;
        TreeNode* curr = nullptr;
        if (!ss.eof()) {
            ss >> temp;
            if (stringstream(temp) >> found) {
                curr = new TreeNode(found);
            }
        }
        if (curr) {
            curr->left = dese(ss);
            curr->right = dese(ss);
        }
        return curr;
    }
};