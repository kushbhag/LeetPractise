// https://leetcode.com/problems/add-strings/
// Easy

#include<string>
using namespace std;

class Solution {
    int charToInt(char c) {
        return c - '0';
    }
    char intToChar(int n) {
        return '0' + n;
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
    string addStrings(string num1, string num2) {
        int carry = 0, temp;
        string sum = "";
        int i = num1.length()-1, j = num2.length()-1;
        while (i >= 0 || j >= 0) {
            if (i >= 0 && j >= 0) {
                temp = charToInt(num1[i]) + charToInt(num2[j]) + carry;
            } else if (i >= 0) {
                temp  = charToInt(num1[i]) + carry;
            } else {
                temp  = charToInt(num2[j]) + carry;
            }
            //cout <<  temp << endl;
            if (temp >= 10) {
                temp -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            sum.push_back(intToChar(temp));
            --i;
            --j;
        }
        if (carry == 1) sum.push_back('1');
        return reverse(sum);
    }
};