// https://leetcode.com/problems/single-number/
// Easy

#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        int sum = 0;
        for (int &n: nums) {
            if (s.find(n) == s.end()) {
                s.insert(n);
                sum += n;
            } else {
                sum -= n;
            }
        }
        return sum;
    }
};

 // Bit Manip
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (int &n: nums) {
            a ^= n;
        }
        return a;
    }
};