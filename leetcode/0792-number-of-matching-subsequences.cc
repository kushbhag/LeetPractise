// https://leetcode.com/problems/number-of-matching-subsequences/
// Medium

#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int len = words.size();
        int count = 0;
        vector<vector<pair<int, int>>> v (26, vector<pair<int, int>> ());
        for (int i = 0; i < len; ++i) {
            v[words[i][0]-'a'].push_back(pair<int, int> (i, 0));
        }
        vector<pair<int, int>> temp;
        for (char &c: S) {
            temp = v[c-'a'];
            v[c-'a'].clear();
            
            for (pair<int, int> &p: temp) {
                if (++p.second >= words[p.first].length()) ++count;
                else {
                    v[words[p.first][p.second]-'a'].push_back(p);
                }
            }
        }
        return count;
    }
};