// https://leetcode.com/problems/3sum/
// Medium

#include<vector>
#include<utility>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 1; ++i) {
            int left = i+1, right = size - 1, sum = -nums[i];
            while (left < right) {
                // cout << left << ' ' << right << endl;
                if (nums[left] + nums[right] > sum) {
                    --right;
                } else if (nums[left] + nums[right] < sum) {
                    ++left;
                } else {
                    v.push_back(vector<int> {nums[i], nums[left], nums[right]});
                    int temp = left;
                    // cout << "I: " << i << endl;
                    // cout << left << ' ' << right << endl;
                    ++temp;
                    if (temp+1 < size && nums[temp] == nums[left]) {
                        while (1) {
                            if (temp+1 >= size || nums[temp] != nums[left]) {
                                // i = temp - 1;
                                // sum = -nums[i];
                                break;
                            }
                            ++temp;
                        }
                    }
                    
                    left = temp;
                    // cout << "I: " << i << endl;
                    // cout << left << ' ' << right << endl;
                }
            }
            if (i+1 < size && nums[i+1] == nums[i]) {
                while(1) {
                    ++i;
                    if (i+1 >= size || nums[i+1] != nums[i]) break;
                }
            }
        }
        return v;
    }
};