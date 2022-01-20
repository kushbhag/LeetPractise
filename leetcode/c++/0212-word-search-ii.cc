// https://leetcode.com/problems/word-search-ii/
// Hard

#include<vector>
#include<unordered_set>

using namespace std;

struct Node {
    bool end = false;
    vector<Node*> nodes;
    Node() {
        nodes = vector<Node*> (26, nullptr);
    }
};

class Trie {
    Node* main;
public:
    /** Initialize your data structure here. */
    Trie(Node *main) {
        this->main = main;
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
        curr->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = main;
        for (char &c: word) {
            if (!curr->nodes[c-'a']) return false;
            curr = curr->nodes[c-'a'];
        }
        return curr->end = true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Solution {
    int rows, cols;
    unordered_set<string> w;
    vector<vector<bool>> checked;
    void dfs(vector<vector<char>>& board, Node* node, int r, int c, string& s, vector<string>& ret) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || checked[r][c]) return;
        if (!node->nodes[board[r][c] - 'a']) {
            return;
        }
        s.push_back(board[r][c]);
        checked[r][c] = true;
        node = node->nodes[board[r][c] - 'a'];
        if (node->end && w.find(s) == w.end()) {
            w.insert(s);
            ret.push_back(s);
        }
        dfs(board, node, r+1, c, s, ret);
        dfs(board, node, r-1, c, s, ret);
        dfs(board, node, r, c-1, s, ret);
        dfs(board, node, r, c+1, s, ret);
        checked[r][c] = false;
        
        s.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* main = new Node();
        Trie* trie = new Trie(main);
        for (string &s: words) {
            trie->insert(s);
        }
        // if (trie->search(words[0])) cout << "HELLO" << endl;
        vector<string> ret;
        rows = board.size();
        cols = board[0].size();
        checked = vector<vector<bool>> (rows, vector<bool> (cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (main->nodes[board[i][j]-'a']) {
                    string s = "";
                    dfs(board, main, i, j, s, ret);
                }
            }
        }
        return ret;
    }
};