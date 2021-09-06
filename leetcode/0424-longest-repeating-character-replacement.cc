// https://leetcode.com/problems/longest-repeating-character-replacement/
// Medium

#include<string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int lo = 0, hi = 0, len = s.length();
        int res = 0;
        int maxCharCount = 0;
        vector<int> v (26, 0);
        for (; hi < len; ++hi) {
            v[s[hi]-'A']++;
            maxCharCount = max(maxCharCount, v[s[hi]-'A']);
            while (hi-lo+1-maxCharCount > k) {
                v[s[lo]-'A']--;
                lo++;

                // The following four lines of code are not needed
                // Since we really already have the maxCharCount before
                maxCharCount = 0;
                for (int i = 0; i < 26; ++i) {
                    maxCharCount = max(maxCharCount, v[i]);
                }
            }
            res = max(res, hi-lo+1);
        }
        return res;
    }
};
