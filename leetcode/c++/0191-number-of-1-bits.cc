// https://leetcode.com/problems/number-of-1-bits/
// Easy

#include <cinttypes>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & 1 == 0) ++count;
            n = n << 1;
        }
        return count;
    }
};