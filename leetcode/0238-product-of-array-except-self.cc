// https://leetcode.com/problems/product-of-array-except-self/
// Medium

#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prod (size+1, 1);
        for (int i = size-1; i >= 1; --i) {
            prod[i] = prod[i+1]*nums[i];
        }
        int curr = nums[0];
        prod[0] = prod[1];
        for (int i = 1; i < size-1; ++i) {
            prod[i] = curr * prod[i+1];
            curr *= nums[i];
        }
        prod[size-1] = curr;
        prod.pop_back();
        return prod;
    }
};