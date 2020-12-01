// https://leetcode.com/problems/perfect-squares/
// Medium
#include<math.h>
#include<limits.h>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> m (n+1, 0);
        m[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int min = INT_MAX;
            for (int j = 1; i/j >= j; ++j) {
                min = m[i-(j*j)] + 1 < min ? m[i-(j*j)] + 1 : min;
            }
            m[i] = min;
        }
        return m[n];
    }
};