using namespace std;

/*
Find the sum of all left leaves in a given binary tree.
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int sumOfLeftLeaf(TreeNode* root, bool left){
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr && left){
            return root->val;
        }
        if (root->left == nullptr && root->right == nullptr && !left){
            return 0;
        }
        return sumOfLeftLeaf(root->left, true) + sumOfLeftLeaf(root->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr){
            return 0;
        }
        //int left = 0;
        //int right = 0;
        //if (root->left) left = sumOfLeftLeaf(root->left, true);
        //if (root->right) right = sumOfLeftLeaf(root->right, false);
        return sumOfLeftLeaf(root->left, true) + sumOfLeftLeaf(root->right, false);
    }
};

int main(){

}