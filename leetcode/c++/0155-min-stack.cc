// https://leetcode.com/problems/min-stack/
// Easy
#include<utility>
#include<vector>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> v1;
    vector<int> v2;
    MinStack() {
    }
    
    void push(int x) {
        if (v2.empty() || v2.back() >= x) {
            v2.push_back(x);
        }
        v1.push_back(x);
    }

    void pop() {
        if (v1.back() == v2.back()) {
            v2.pop_back();
        }
        v1.pop_back();
    }

    int top() {
        return v1.back();
    }

    int getMin() {
        return v2.back();
    }
};