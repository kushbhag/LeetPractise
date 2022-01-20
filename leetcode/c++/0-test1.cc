#include<vector>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include<sstream>


vector<int> parseString(string s) {
  stringstream ss (s);
  vector<int> mem;
  string temp;
  while (ss.good()) {
    getline(ss, temp, ',');
    mem.push_back(stoi(temp));
  }
  return mem;
}