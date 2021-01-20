// https://leetcode.com/problems/clone-graph/
// Medium
// Mock

#include<vector>
#include<unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    Node* clonedGraphRec(Node* node, unordered_map<int, Node*>& m) {
        Node* n = new Node();
        n->val = node->val;
        m[node->val] = n;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            if (m.find(node->neighbors[i]->val) != m.end()) {
                n->neighbors.push_back(m[node->neighbors[i]->val]);
            } else {
                n->neighbors.push_back(clonedGraphRec(node->neighbors[i], m));
            }
        }

        return n;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<int, Node*> m;
        return clonedGraphRec(node, m);
    }
};