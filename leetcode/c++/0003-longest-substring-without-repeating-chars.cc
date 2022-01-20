// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Medium

#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int lo = 0, hi = 0, maxSoFar = 0;
        int a [128] = {0};
        while(hi < len) {
            a[s[hi]]++;
            while (a[s[hi]] > 1) {
                a[s[lo]]--;
                lo++;
            }
            maxSoFar = max(maxSoFar, hi-lo+1);
            ++hi;
        }
        return maxSoFar;
    }
};