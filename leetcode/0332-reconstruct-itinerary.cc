// https://leetcode.com/problems/reconstruct-itinerary/
// Medium

#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
    unordered_map<string, multiset<string>> m;
    vector<string> v;
    void visit(string s) {
        while (!m[s].empty()) {
            string next = *m[s].begin();
            m[s].erase(m[s].begin());
            visit(next);
        }
        v.push_back(s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (vector<string>& v: tickets) {
            m[v[0]].insert(v[1]);
        }
        visit("JFK");
        return vector<string> (v.rbegin(), v.rend());
    }
};