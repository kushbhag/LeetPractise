// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
// Medium

#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    int longestSubstringRec(string s, int k, int start, int end) {
        if (start >= end || end-start+1 < k) return 0;
        int v[26] = {0};
        for (int i = start; i <= end; ++i) {
            v[s[i]-'a']++;
        }
        // cout << start << ' ' << end << endl;
        for (int i = start; i <= end; ++i) {
            if (v[s[i]-'a'] < k) {
                for (int j = i+1; j <= end; ++j) {
                    if (v[s[j]-'a'] >= k) {
                        return max(longestSubstringRec(s, k, 0, i-1),
                                   longestSubstringRec(s, k, j, end));
                    }
                }
                // return max(longestSubstringRec(s, k, 0, i-1),
                //                    longestSubstringRec(s, k, i+1, end));
                return longestSubstringRec(s, k, 0, i-1);
            }
        }
        return end-start+1;
    }
public:
    int longestSubstring(string s, int k) {
        if (s.empty()) return 0;
        if (k == 1 || k == 0) return s.length();
        return longestSubstringRec(s, k, 0, s.length()-1);
    }
};