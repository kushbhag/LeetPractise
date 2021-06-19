// https://leetcode.com/problems/jump-game-vi/
// Medium
// June 9th, 2021 Challenge

#include<vector>
#include<deque>
using namespace std;

// Using a decreasing deque
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> d;
        int size = nums.size();
        d.push_back(nums[0]);
        for (int i = 1; i < size; ++i) {
            nums[i] = nums[i] + nums[d.front()];

            while (!d.empty() && nums[d.back()] < nums[i]) {
                d.pop_back();
            }
            d.push_back(i);
            if (d.front() > i-k) {
                d.pop_front();
            }
        }
        return nums[d.front()];
    }
};

// Naive: O(nk) solution
class NaiveSolution {
public:
    int maxResult(vector<int>& nums, int k) {
        int size = nums.size(), index;
        vector<double> scores (size, INT_MIN);
        scores[0] = nums[0];
        for (int i = 0; i <= size - 1; ++i) {
            int currScore = scores[i];
            // cout << currScore <<": ";
            for (int j = 1; j <= k; ++j) {
                if (j+i == size) break;
                index = j + i;
                scores[index] = max((int)scores[index], nums[index] + currScore);
            }
        }
        return scores[size-1];
    }
};