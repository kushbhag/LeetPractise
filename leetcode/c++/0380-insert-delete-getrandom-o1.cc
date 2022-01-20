// https://leetcode.com/problems/insert-delete-getrandom-o1/
// Medium

#include<list>
#include<unordered_map>
using namespace std;

class RandomizedSet {
    unordered_map<int, int> m;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        v.push_back(val);
        m[val] = v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        swap(v[m[val]], v[v.size()-1]);
        m[v[m[val]]] = m[val];
        v.pop_back();
        m.erase(val);
        // for(int &n: v) {
        //     cout << n << ' ';
        // }
        // cout << endl;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */