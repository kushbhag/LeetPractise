#include<list>
#include<iostream>
using namespace std;

class FrontMiddleBackQueue {
    list<int> x;
    list<int> y;

    void balance() {
        if (y.size() > x.size() + 1) {
            int temp = y.front();
            y.pop_front();
            x.push_back(temp);
        } else if (x.size() > y.size()) {
            int temp = x.back();
            x.pop_back();
            y.push_front(temp);
        }
    }

public:
    FrontMiddleBackQueue() { }
    
    void pushFront(int val) {
        x.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        y.push_front(val);
        balance();
    }
    
    void pushBack(int val) {
        y.push_back(val);
        balance();
    }
    
    int popFront() {
        int front;
        if (x.size() == 0 && y.size() > 0) {
            front = y.front();
            y.pop_front();
        } else if (x.size() > 0) {
            front = x.front();
            x.pop_front();
        } else {
            front = -1;
        }
        balance();
        return front;
    }
    
    int popMiddle() {
        int middle;
        if (y.size() == 0) {
            middle = -1;
        } else if (x.size() == y.size()) {
            middle = x.back();
            x.pop_back();
        } else {
            middle = y.front();
            y.pop_front();
        }
        return middle;
    }
    
    int popBack() {
        int back;
        if (y.size() > 0) {
            back = y.back();
            y.pop_back();
        } else {
            back = -1;
        }
        balance();
        return back;
    }
};