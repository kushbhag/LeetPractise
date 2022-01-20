// https://leetcode.com/problems/count-and-say/
// Easy
#include<string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string s = countAndSay(n-1);
        string ret = "";
        int len = s.length();
        int currLen = 1;
        for (int i = 0; i < len;) {
            int j = i+1;
            while (j < len && s[i] == s[j]) { 
                ++currLen;
                ++j;
            }
            ret += to_string(currLen) + s[i];
            currLen = 1;
            i = j;
        }
        
        return ret;
    }
};