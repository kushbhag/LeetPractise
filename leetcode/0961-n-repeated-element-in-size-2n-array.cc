// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
// Easy
// Mock

#include<unordered_set>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> s;
        for (int &n: A) {
            if (s.find(n) == s.end()) {
                s.insert(n);
            } else {
                return n;
            }
        }
        return 1;
    }
};