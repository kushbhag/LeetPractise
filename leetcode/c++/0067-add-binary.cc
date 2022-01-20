// https://leetcode.com/problems/add-binary/
// Easy

#include<string>

using namespace std;

class Solution {
    int charToInt(char c) {
        return c - '0';
    }
    string reverse(string s) {
        string ret;
        int len = s.length();
        for (int i = len-1; i >= 0; --i) {
            ret.push_back(s[i]);
        }
        return ret;
    }
public:
    string addBinary(string a, string b) {
        int i = a.length()-1, j = b.length()-1;
        int temp, carry = 0;
        string ret = "";
        while (i >= 0 || j >= 0) {
            if (i >= 0 && j >= 0) {
                temp = charToInt(a[i]) + charToInt(b[j]) + carry;
            } else if (i >= 0) {
                temp = charToInt(a[i]) + carry;
            } else {
                temp = charToInt(b[j]) + carry;
            }
            if (temp == 3) {
                ret.push_back('1');
                carry = 1;
            } else if (temp == 2) {
                ret.push_back('0');
                carry = 1;
            } else if (temp == 1) {
                ret.push_back('1');
                carry = 0;
            } else {
                ret.push_back('0');
                carry = 0;
            }
            --i;
            --j;
        }
        if (carry == 1) ret.push_back('1');
        return reverse(ret);
    }
};