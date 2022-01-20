// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
// Easy
// Mock

#include<vector>
#include<unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        int minSize = INT_MAX;
        for (int n: deck) {
            ++m[n];
        }
        for (auto p: m) {
            if(minSize == INT_MAX) minSize = p.second;
            minSize = min(gcd(p.second, minSize), minSize);
        }
        if (minSize < 2) return false;
        for (auto p: m) {
            if (p.second % minSize != 0) return false;
        }
        return true;
    }
};