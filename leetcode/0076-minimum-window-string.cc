// https://leetcode.com/problems/minimum-window-substring/
// Hard

#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        int len = s.length();
        for (char &c: t) { m[c]++; }

        int r = 0, l = 0, counter = t.length();
        int minLen = INT_MAX;
        string minString = "";
        while (r < len) {
            if (m[s[r]]-- > 0) counter--;
            //++r;
            while (counter == 0) {
                //cout << l << ' ' << r << endl;
                if (r-l+1 < minLen) {
                    minLen = r-l+1;
                    //
                    minString = s.substr(l, minLen);
                }
                if(m[s[l]]++==0) counter++;  //make it invalid
                ++l;
            }
            ++r;
        }
        return minString;

    }
};