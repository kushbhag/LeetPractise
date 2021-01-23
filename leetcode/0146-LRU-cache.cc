// https://leetcode.com/problems/lru-cache/
// Medium
#include<list>
#include<unordered_map>
using namespace std;

class LRUCache {
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m;
    int maxSize;

    void reorder(int key) {
        l.push_front(pair<int, int> (key, (*m[key]).second));
        l.erase(m[key]);
        m[key] = l.begin();
    }
public:
    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        reorder(key);
        return l.front().second;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            reorder(key);
            l.front().second = value;
        } else if (l.size() == maxSize) {
            m.erase(l.back().first);
            l.push_front(pair<int, int> (key, value));
            l.pop_back();
            m[key] = l.begin();
        } else {
            l.push_front(pair<int, int> (key, value));
            m[key] = l.begin();
        }
    }
};
