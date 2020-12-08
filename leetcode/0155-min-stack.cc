// https://leetcode.com/problems/min-stack/
// Easy
#include<utility>
#include<vector>
using namespace std;

// SHOULDVE USED TWO VECTORS INSTEAD
class MinStack2 {
public:
    /** initialize your data structure here. */
    vector<int> v;
    pair<int, int> p;
    MinStack2() {
        p = pair<int, int> (INT_MAX, 0);
    }
    
    void push(int x) {
        v.push_back(x);
        if (x < p.first) {
            p.second = 0;
            p.first = x;
        } else {
            ++p.second;
        }
    }

    void pop() {
        v.pop_back();
        --p.second;
        if (p.second <= 0) {
            p.first = INT_MAX;
            int size = v.size();
            for (int i = 0; i < size; ++i) {
                if (v[i] < p.first) {
                    p.second = size-i-1;
                    p.first = v[i];
                }
            }
        }

    }

    int top() {
        return v.back();
    }

    int getMin() {
        return p.first;
    }
};


class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> v;
    vector<int> mins;
    MinStack() {
    }
    
    void push(int x) {
        v.push_back(x);
        int temp = x;
        for (int i = 0; i < mins.size(); ++i) {
            if (temp < mins[i]) {
                swap(mins[i], temp);
            }
        }
        mins.emplace_back(temp);
    }

    void pop() {
        int popped = v.back();
        v.pop_back();
        for (int i = 0; i < mins.size() - 1; ++i) {
            if (mins[i] == popped) {
                swap(mins[i], mins[i+1]);
            }
        }
        mins.pop_back();
    }

    int top() {
        return v.back();
    }

    int getMin() {
        return mins.front();
    }
};