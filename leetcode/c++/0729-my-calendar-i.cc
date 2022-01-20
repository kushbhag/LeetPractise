// https://leetcode.com/problems/my-calendar-i/
// Medium
// June 10, 2021 Challenge

#include<utility>

using namespace std;

class BTree {
public:
    pair<int, int> range;
    BTree* left, *right;
    BTree() {}
    ~BTree() {
        delete left;
        delete right;
    }
    BTree(pair<int, int> range, BTree* left, BTree* right): range{range}, left{left}, right{right} {}
};

class MyCalendar {
    BTree* head;
public:
    MyCalendar() {
        head = nullptr;
    }
    ~MyCalendar() {
        delete head;
    }
    
    bool book(int start, int end) {
        // cout << "BOOK: " << start << " " << end << endl;
        if (head == nullptr) {
            head = new BTree(pair<int, int> (start, end), nullptr, nullptr);
            return true;
        }
        BTree* curr = head;
        while (1) {
            // cout << curr->range.first << " " << curr->range.second << endl;
            if (curr->range.first <= start && curr->range.second > start) return false;
            else if (curr->range.first < end && curr->range.second >= end) return false;
            else if (start <= curr->range.first && curr->range.second <= end) return false;
            else if (curr->range.first >= end) {
                if (curr->left == nullptr) {
                    curr->left = new BTree(pair<int, int> (start, end), nullptr, nullptr);
                    return true;
                }
                curr = curr->left;
            } else if (curr->range.second <= start) {
                if (curr->right == nullptr) {
                    curr->right = new BTree(pair<int, int> (start, end), nullptr, nullptr);
                    return true;
                }
                curr = curr->right;
            }
        }
        return false;
    }
};