// https://leetcode.com/problems/group-anagrams/
// Medium
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
    string sortString(string s) {
        sort(s.begin(), s.end());
        return s;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;
        vector<vector<string>> ret;
        for (auto s: strs) {
            string sorted = sortString(s);
            if (m.find(sorted) == m.end()) {
                m[sorted] = ret.size();
                vector<string> v;
                v.push_back(s);
                ret.push_back(v);
            } else {
                ret[m[sorted]].push_back(s);
            }
        }
        return ret;
    }
};