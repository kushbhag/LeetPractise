// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Medium

#include<vector>
#include<string>
#include<deque>
using namespace std;

class Solution {
    void letterCombinationsMemo(string& digits, int index, deque<string>& ret) {
        if (index == digits.length()) {
            ret.push_back("");
            return;
        }
        letterCombinationsMemo(digits, index + 1, ret);
        int size = ret.size();
        string s;
        if (digits[index] == '2') {
            for (int i = 0; i < size; ++i) {
                s = ret.back();
                ret.pop_back();
                ret.push_front("a" + s);
                ret.push_front("b" + s);
                ret.push_front("c" + s);
            }
        } else if (digits[index] == '3') {
            for (int i = 0; i < size; ++i) {
                s = ret.back();
                ret.pop_back();
                ret.push_front("d" + s);
                ret.push_front("e" + s);
                ret.push_front("f" + s);
            }
        } else if (digits[index] == '4') {
            for (int i = 0; i < size; ++i) {
                s = ret.back();
                ret.pop_back();
                ret.push_front("g" + s);
                ret.push_front("h" + s);
                ret.push_front("i" + s);
            }
        } else if (digits[index] == '5') {
            for (int i = 0; i < size; ++i) {
                s = ret.back();
                ret.pop_back();
                ret.push_front("j" + s);
                ret.push_front("k" + s);
                ret.push_front("l" + s);
            }
        } else if (digits[index] == '6') {
            for (int i = 0; i < size; ++i) {
                s = ret.back();
                ret.pop_back();
                ret.push_front("m" + s);
                ret.push_front("n" + s);
                ret.push_front("o" + s);
            }
        } else if (digits[index] == '7') {
            for (int i = 0; i < size; ++i) {
                s = ret.back();
                ret.pop_back();
                ret.push_front("p" + s);
                ret.push_front("q" + s);
                ret.push_front("r" + s);
                ret.push_front("s" + s);
            }
        } else if (digits[index] == '8') {
            for (int i = 0; i < size; ++i) {
                s = ret.back();
                ret.pop_back();
                ret.push_front("t" + s);
                ret.push_front("u" + s);
                ret.push_front("v" + s);
            }
        } else if (digits[index] == '9') {
            for (int i = 0; i < size; ++i) {
                s = ret.back();
                ret.pop_back();
                ret.push_front("w" + s);
                ret.push_front("x" + s);
                ret.push_front("y" + s);
                ret.push_front("z" + s);
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return vector<string> ();
        deque<string> v;
        letterCombinationsMemo(digits, 0, v);
        vector<string> ret (v.begin(), v.end());
        return ret;
    }
};