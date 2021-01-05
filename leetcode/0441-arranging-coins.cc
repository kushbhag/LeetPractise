// https://leetcode.com/problems/arranging-coins/
// Easy

class Solution {
public:
    int arrangeCoins(int n) {
        int i = 0, j = 1;
        while(n >= 0) {
            n -= j++;
            ++i;
        }
        return n == 0 ? i : i - 1;
    }
};