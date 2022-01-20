// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// Medium

#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
    int maxSoFar = 0, size = 0;

    void maxLengthRec(vector<string>& arr, int currIndex, vector<int>& v) {
        int count = 0;
        for (int &n: v) {
            if (n >= 2) return;
            else if (n == 1) ++count;
        }
        maxSoFar = max(count, maxSoFar);
        for (int i = currIndex; i < size; ++i) {
            for (char &c: arr[i]) {
                v[c-'a']++;
            }
            maxLengthRec(arr, i+1, v);
            for (char &c: arr[i]) {
                v[c-'a']--;
            }
        }
    }
public:
    int maxLength(vector<string>& arr) {
        size = arr.size();
        vector<int> v (26, 0);
        maxLengthRec(arr, 0, v);
        return maxSoFar;
    }
};