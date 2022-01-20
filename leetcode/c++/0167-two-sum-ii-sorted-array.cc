// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Easy

#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while(low < high) {
            if (numbers[low] + numbers[high] == target) {
                return vector<int> {low+1, high+1}; // Because index is not supposed to be zero-based
            } else if (numbers[low] + numbers[high] > target) {
                --high;
            } else {
                ++low;
            }
        }
        return vector<int> ();
    }
};