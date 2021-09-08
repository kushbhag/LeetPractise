// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
// Easy

#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        if (n % 2 != 0) v.push_back(0);
        for (int i = n/2; i > 0; --i) {
            v.push_back(-i);
            v.push_back(i);
        }
        return v;
        
    }
};