// https://leetcode.com/problems/matchsticks-to-square/
// Medium
// June 15th, Challenge

#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
    int size, len;
    bool makesquareRec(vector<int>& v, int i, int s1, int s2, int s3, int s4) {
        if (i == size) {
            if (s1 == s2 && s2 == s3 && s3 == s4) return true;
            else return false;
        } else if (s1 > len || s2 > len || s3 > len || s4 > len) {
            return false;
        }
        if (s1 == 0) {
            return makesquareRec(v, i+1, s1 + v[i], s2, s3, s4);
        } else if (s2 == 0) {
            return makesquareRec(v, i+1, s1 + v[i], s2, s3, s4) ||
                   makesquareRec(v, i+1, s1, s2 + v[i], s3, s4);
        } else if (s3 == 0) {
            return makesquareRec(v, i+1, s1 + v[i], s2, s3, s4) ||
                   makesquareRec(v, i+1, s1, s2 + v[i], s3, s4) ||
                   makesquareRec(v, i+1, s1, s2, s3 + v[i], s4);
        }
        return makesquareRec(v, i+1, s1 + v[i], s2, s3, s4) || 
               makesquareRec(v, i+1, s1, s2 + v[i], s3, s4) ||
               makesquareRec(v, i+1, s1, s2, s3 + v[i], s4) || 
               makesquareRec(v, i+1, s1, s2, s3, s4 + v[i]);
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        size = matchsticks.size();
        for (int i = 0; i < size; ++i) {
            sum += matchsticks[i];
        }
        if (sum % 4 != 0) return false;
        len = sum / 4;

        return makesquareRec(matchsticks, 0, 0, 0, 0, 0);
    }
};