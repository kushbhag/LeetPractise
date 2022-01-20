// https://leetcode.com/problems/decode-ways/
// Medium

#include<unordered_map>
#include<vector>
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

// DP Solution
class Solution1 {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 1) return s == "0" ? 0 : 1;
        vector<int> v (len+1, 0);
        if(s[len-1] != '0') {
            v[len-1] = 1;
        } 
        v[len] = 1;
        int count;
        for (int i = len-2; i >= 0; --i) {
            count = 0;
            for (int j = 1; j <= 2; ++j) {
                string temp = s.substr(i, j);
                if (temp == "0" || temp == "00") {
                    count = 0;
                    break;
                }
                if (stoi(temp) <= 26) {
                    count += v[i+j];
                }
            }
            v[i] = count;
        }
        return v[0];
    }
};

int main() {

}