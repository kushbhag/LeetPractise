// https://leetcode.com/problems/contains-duplicate-iii/
// Medium

#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
    int len;
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        len = nums.size();
        unordered_map<long, int> m;

        int lower = 0;
        for (int i = 0; i < len; ++i) {
            if (i > k) {
                m.erase(nums[lower++]);
            }
            if (k/2 < t) {
                for (pair<long, int> p: m) {
                    if (abs(p.first - (long)nums[i]) <= t) return true;
                }
            } else {
                for (int j = -t; j <= t; ++j) {
                    //if (INT_MAX - abs(nums[i]) < j  || INT_MIN + abs(nums[i]) > j) continue;
                    //cout <<  nums[i] << ' ' << j << endl;
                    if (m.find(j+(long)nums[i]) != m.end()) {
                        //cout << j + (long)nums[i];
                        return true;
                    }
                }
            }
            
            
            m[nums[i]] = i;
        }
        return false;
    }
};