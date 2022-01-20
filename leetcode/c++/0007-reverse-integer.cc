// https://leetcode.com/problems/reverse-integer/
// Easy

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        bool neg = x < 0;
        x = x < 0 ? -x : x;
        int ret = 0;
        while (x > 0) {
            if (INT_MAX / 10 < ret) {
                return 0;
            }
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return neg ? -ret : ret;
    }
};