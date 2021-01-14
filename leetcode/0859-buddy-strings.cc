// https://leetcode.com/problems/buddy-strings/
// Easy
// Mock

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        int len1 = A.length(), len2 = B.length();
        vector<int> v (26, 0);
        if (len1 != len2 || len1 < 2 || len2 < 2) return false;

        int temp1 , temp2 = -1;
        for (int i = 0; i < len1; ++i) {
            v[A[i]-'a']++;
            if (A[i] != B[i]) {
                for (int j = i+1; j < len1; ++j) {
                    if (A[j] != B[j] && temp2 == -1 && A[i] == B[j] && A[j] == B[i]) {
                        temp2 = j;
                    } else if (A[j] != B[j]) {
                        return false;
                    }
                }
                return temp2 == -1 ? false : true;
            }
        }
        for (int &n: v) {
            if (n > 1) return true;
        }
        return false;
    }
};