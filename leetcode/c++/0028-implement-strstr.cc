// https://leetcode.com/problems/implement-strstr/
// Easy

#include<string>
#include<vector>
using namespace std;

class Solution {
    int lenHay, lenNeedle;
public:
    int strStr(string haystack, string needle) {
        lenHay = haystack.length();
        lenNeedle = needle.length();
        if (lenHay < lenNeedle) return -1;
        if (lenNeedle == 0) return 0;
        vector<int> v (127, lenNeedle);
        for (int i = 0; i < lenNeedle-1; ++i) {
            v[needle[i]] = lenNeedle - i - 1;
        }
        for (int i = lenNeedle - 1; i < lenHay; i += v[haystack[i]]) {
            // cout << i << endl;
            // cout << v[haystack[i]] << endl;
            if (haystack[i] == needle[lenNeedle - 1]) {
                int j2 = lenNeedle - 2;
                for (int j1 = i-1; j2 >= 0; --j1, --j2) {
                    if (haystack[j1] != needle[j2]) break;
                }
                if (j2 < 0) return i-lenNeedle+1;
            }
        }
        return -1;
    }
};