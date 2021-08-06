// https://leetcode.com/problems/map-sum-pairs/
// Medium
// July 30th, 2021 Challenge

#include<string>
#include<vector>
using namespace std;

class MapSum {
    struct Trie {
        Trie* children[26] = {};
        int sum = 0;
        
        Trie() {

        }
        
        ~Trie() {
            for (int i = 0; i < 26; ++i) {
                if (children[i] != nullptr) delete children[i];
            }
        }
    };
public:
    Trie* root;
    unordered_map<string, int> m;
    /** Initialize your data structure here. */
    MapSum() {
        root = new Trie();
    }
    
    void insert(string key, int val) {
        int len = key.length();
        Trie* head = root;
        int sub = 0;
        if (m.find(key) != m.end()) sub = m[key];
        for (int i = 0; i < len; ++i) {
            if (head->children[key[i]-'a'] == nullptr) {
                head->children[key[i]-'a'] = new Trie();
            }
            head = head->children[key[i]-'a'];
            head->sum += val - sub;
        }
        m[key] = val;
    }
    
    int sum(string prefix) {
        Trie* head = root;
        int len = prefix.length();
        for (int i = 0; i < len && head != nullptr; ++i) {
            head = head->children[prefix[i]-'a'];
        }
        return head == nullptr ? 0 : head->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */