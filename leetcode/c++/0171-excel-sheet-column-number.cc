// https://leetcode.com/problems/excel-sheet-column-number/
// Easy

#include<string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int total = 0;
        for (int i = s.length()-1, j = 1; i >= 0; --i) {
            total += (s[i] - 'A' + 1) * j;
            if (INT_MAX / 26 > j) j *= 26;
        }
        return total;
    }
};