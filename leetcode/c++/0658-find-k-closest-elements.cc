// https://leetcode.com/problems/find-k-closest-elements/
// Medium
// July 2nd, 2021 Challenge

#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> diff = arr;
        for (int &a: arr) {
            a = abs(x - a);
        }
        int size = arr.size();
        int theLo = 0, theHi = k-1;
        int tempSum = 0;
        for (int i = 0; i < k-1; ++i) {
            tempSum += arr[i];
        }
        int mi = INT_MAX;
        for(int lo = 0, hi = k-1; hi < size; ++hi, ++lo) {
            tempSum += arr[hi];
            if (tempSum < mi) {
                mi = tempSum;
                theLo = lo;
                theHi = hi;
            }
            tempSum -= arr[lo];
        }
        return vector<int> (diff.begin()+theLo, diff.begin()+theHi+1);
    }
};