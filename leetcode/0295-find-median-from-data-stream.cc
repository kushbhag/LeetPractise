// https://leetcode.com/problems/find-median-from-data-stream/
// Hard
// July 11th, 2021 Challenge
#include<queue>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lo.size() > hi.size()) {
            int top = lo.top();
            if (num < top) {
                lo.pop();
                hi.push(top);
                lo.push(num);
            } else {
                hi.push(num);
            }
        } else {
            if (!lo.empty() && num > hi.top()) {
                int temp = hi.top();
                hi.pop();
                hi.push(num);
                lo.push(temp);
            } else {
                lo.push(num);
            }
        }
    }
    
    double findMedian() {
        if (lo.size() == hi.size()) {
            return (double)lo.top() / (double)hi.top();
        }
        return lo.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */