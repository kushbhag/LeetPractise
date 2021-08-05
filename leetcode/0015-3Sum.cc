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
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        
        int size = nums.size();

        for (int i = 0; i < size;) {
            int lo = i+1;
            int hi = size-1;

            while (lo < hi) {
                int sum = nums[lo] + nums[hi] + nums[i];
                if (sum < 0) {
                    ++lo;
                } else if (sum > 0) {
                    --hi;
                } else {
                    ret.push_back({nums[i], nums[lo], nums[hi]});
                    ++lo;
                    while (lo < hi && nums[lo] == nums[lo-1]) ++lo;
                }
            }
            ++i;
            while (i > 0 && i < size && nums[i] == nums[i-1]) ++i;
        }
        return ret;
    }
};
class Solution1 {
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