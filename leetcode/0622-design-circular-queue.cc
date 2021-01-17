// https://leetcode.com/problems/design-circular-queue/
// Medium
// Mock

using namespace std;

#include<deque>
#include<vector>

// Using deque
class MyCircularQueue {
    deque<int> d;
    int maxSize;
public:
    MyCircularQueue(int k) {
        maxSize = k;
        d = deque<int> ();
    }
    
    bool enQueue(int value) {
        int size = d.size();
        //cout << size-1 << ' ' << maxSize << endl;
        if (size < maxSize) {
            //cout << "ENQUE "<< endl;
            d.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        //cout << "DEQUE "<< endl;
        if (!d.empty()) {
            d.pop_front();
            return true;
        }
        return false;
    }
    
    int Front() {
        //cout << "FRONT "<< endl;
        return d.empty() ? -1 : d.front();
    }
    
    int Rear() {
        //cout << "REAR "<< endl;
        return d.empty() ? -1 : d.back();
    }
    
    bool isEmpty() {
        //cout << "EMPTY "<< endl;
        return d.empty();
    }
    
    bool isFull() {
        //cout << "FULL "<< endl;
        //cout << d.size() << ' ' << maxSize << endl;
        return d.size() == maxSize;
    }
};

// Using vectors and two pointers
class MyCircularQueue {
    vector<int> v;
    int maxSize, front, back, size = 0;
public:
    MyCircularQueue(int k) {
        maxSize = k;
        front = 0;
        back = 0;
        v = vector<int> (k);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        if (!isEmpty()) back = (back+1) % maxSize;
        v[back] = value;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        --size;
        if (!isEmpty()) front = (front+1) % maxSize;
        return true;
    }
    
    int Front() {
        //cout << "FRONT "<< endl;
        return isEmpty() ? -1 : v[front];
    }
    
    int Rear() {
        //cout << "REAR "<< endl;
        return isEmpty() ? -1 : v[back];
    }
    
    bool isEmpty() {
        //cout << "EMPTY "<< endl;
        return size == 0;
    }
    
    bool isFull() {
        //cout << "FULL "<< endl;
        //cout << d.size() << ' ' << maxSize << endl;
        return size == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */