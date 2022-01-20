// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
// Medium

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int begin = target / arr.size();
        int a = INT_MAX, currSum = 0, minNum = begin;
        int size = arr.size();
        for (int i = 0; i < size; ++i) {
            while (begin <= arr[i]) {
                if (abs(target - (currSum + (size-i)*begin)) < a) {
                    a = abs(target - (currSum + (size-i)*begin));
                    //cout << a << ' ' << begin << endl;
                    minNum = begin;
                }
                ++begin;
            }
            currSum += arr[i];
            //cout << currSum << endl;
        }
        return minNum;
    }
};