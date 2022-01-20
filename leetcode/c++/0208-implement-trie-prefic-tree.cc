// https://leetcode.com/problems/implement-trie-prefix-tree/
// Medium

#include<vector>

using namespace std;

class Trie {
    struct Node {
        vector<Node*> nodes;
        Node() {
            nodes = vector<Node*> (27, nullptr);
        }
        ~Node() {
            for (int i = 0; i < 27; ++i) {
                if (nodes[i]) delete nodes[i];
            }
        }
    };

    Node* main = new Node();
public:
    /** Initialize your data structure here. */
    Trie() {
    }
    
    ~Trie() {
        delete main;
    }
    
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = main;
        for (char &c: word) {
            if (!curr->nodes[c-'a']) {
                curr->nodes[c-'a'] = new Node();
            }
            curr = curr->nodes[c-'a'];
        }
        if (!curr->nodes[26]) {
            curr->nodes[26] = new Node();
            curr->nodes[26]->c = '\0';
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = main;
        for (char &c: word) {
            if (!curr->nodes[c-'a']) return false;
            curr = curr->nodes[c-'a'];
        }
        return curr->nodes[26] ? true : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = main;
        for (char &c: prefix) {
            if (!curr->nodes[c-'a']) return false;
            curr = curr->nodes[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */