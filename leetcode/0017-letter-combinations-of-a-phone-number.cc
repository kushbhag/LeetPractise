// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Medium

#include<vector>
#include<string>
#include<deque>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string> ();
        vector<string> dictionary = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        deque<string> v;
        v.push_back("");
        for (int i = digits.length()-1; i >= 0; --i) {
            int num = digits[i]-'0';
            int size = v.size();
            for (int i = 0; i < size; ++i) {
                string s = v.back();
                v.pop_back();
                for (char c: dictionary[num]) {
                    v.push_front(c + s);
                }
            }
        }
        vector<string> ret (v.begin(), v.end());
        return ret;
    }
};