// https://leetcode.com/problems/plus-one/
// Easy

#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return digits;
        int len = digits.size(), carry = 0;
        ++digits[len-1];
        for (int i = len-1; i>=0; --i) {
            digits[i] += carry;
            if (digits[i] >= 10) {
                digits[i] -= 10;
                carry = 1;
            } else {
                return digits;
            }
        }
        //digits.insert(digits.begin(), 1);
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};