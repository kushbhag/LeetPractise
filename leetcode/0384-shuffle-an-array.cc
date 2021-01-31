// https://leetcode.com/problems/shuffle-an-array/
// Medium

#include<vector>

using namespace std;

class Solution {
    vector<int> original;
    vector<int> curr;
public:
    Solution(vector<int>& nums) {
        original = nums;
        curr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        curr = original;
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int size = curr.size();
        for (int i = 0; i < size-1; ++i) {
            
            //int r = rand() % (size-i);
            //cout << size-i << ' '<< r<< ' ' << rand() % (size-i) << endl;
            swap(curr[i], curr[rand() % (size-i)+i]);
        }
        return curr;
    }
};