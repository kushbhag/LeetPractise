// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Medium

#include<string>
#include<vector>

using namespace std;

class Solution {
    int maxSoFar = 0, low = 0, hi = 0, size, tempMax;
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> alpha (96, false);
        size = s.length();
        while (hi < size) {
            if (alpha[s[hi] - ' ']) {
                if (low == hi) {
                    ++hi;
                } else {
                    alpha[s[low] - ' '] = false;
                    ++low;
                    --tempMax;
                }
            } else {
                alpha[s[hi] - ' '] = true;
                ++tempMax;
                ++hi;
                maxSoFar = tempMax > maxSoFar ? tempMax : maxSoFar;
            }
        }
        return maxSoFar;
    }
};