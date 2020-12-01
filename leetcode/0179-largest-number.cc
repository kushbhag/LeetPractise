#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool mySort(string i, string j) {
    return i + j > j + i;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto &n: nums) {
            strs.push_back(to_string(n));
        }
        sort(strs.begin(), strs.end(), mySort);
        string ret = "";
        if (strs[0] == "0") return "0";
        for (auto &n: strs) {
            ret += n;
        }
        return ret;
    }
};

int main() {
    
}