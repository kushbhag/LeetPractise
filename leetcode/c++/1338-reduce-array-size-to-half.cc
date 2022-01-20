// https://leetcode.com/problems/reduce-array-size-to-the-half/
// Medium
// July 6th, 2021 Challenge

#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int size = arr.size();
        vector<int> v;
        int count = 1;
        for (int i = 1; i < size; ++i) {
            if (arr[i] != arr[i-1]) {
                v.push_back(count);
                count = 1;
            } else {
                ++count;
            }
        }
        v.push_back(count);
        sort(v.begin(), v.end(), greater<int>());
        count = 0;
        int size2 = v.size(), expected = size/2;
        for (int i = 0; i < size2; ++i) {
            count += v[i];
            if (count >= expected) {
                return i+1;
            }
        }
        return size;
    }
};