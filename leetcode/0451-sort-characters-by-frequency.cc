// https://leetcode.com/problems/sort-characters-by-frequency/
// Medium

#include<string>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (char &c: s) m[c]++;
        set<pair<int, char>, greater<pair<int,char>>> ss;
        for (pair<char, int> p: m) {
            ss.insert(pair<int, char> {p.second, p.first});
        }
        string ret;
        while (!ss.empty()) {
            pair<int, char> p = *ss.begin();
            for (int i = 0; i < p.first; ++i) {
                ret.push_back(p.second);
            }
            ss.erase(ss.begin());
        }
        return ret;
    }
};