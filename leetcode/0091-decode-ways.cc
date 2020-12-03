// https://leetcode.com/problems/decode-ways/
// Medium

#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;

class Solution {
    int numDecodingsMemo(string s, unordered_map<string, int>& m){
        if (m.find(s) != m.end()) {
            return m[s];
        }
        int len = s.length();
        if (s == "0" || s == "00") {
            return 0;
        }
        if (len == 1) {
            return 1;
        }

        if (s[0] == '0') return 0;
        int sum = numDecodingsMemo(s.substr(1, len), m);
        string temp = s.substr(0, 2);
        if (temp <= "26") {
            if (len - 2 > 0) {
                int x = numDecodingsMemo(s.substr(2, len), m);
                if (x != 0) {
                    sum += x;
                }
            } else {
                sum ++;
            }
        }
        m[s] = sum;
        return sum;
    }
public:
    int numDecodings(string s) {
        unordered_map<string, int> m;
        return numDecodingsMemo(s, m);
    }
};

int main() {
    string s = "26";
    string s1 = "27";
    cout << (s1 > "19") << endl;
}