// https://leetcode.com/problems/decode-string/
// Medium

#include<string>

using namespace std;

class Solution {
    bool isnum(char c) {
        return c == '0' || c == '1' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9';
    }
public:
    string decodeString(string s) {
        //cout << s << endl;
        int len = s.length();
        string ret = "";
        for (int i = 0; i < len; ++i) {
            if (isnum(s[i])) {
                int k = i+1;
                for (; k <len; ++k) {
                    if (!isnum(s[k])) {
                        break;
                    }
                }
                int theNum = stoi(s.substr(i, k-i));
                //cout << theNum << ' ' << k << endl;
                int counter = 0;
                for (int j = k+1; j < len; ++j) {
                    if (s[j] == '[') {
                        counter++;
                    } else if (s[j] == ']') {
                        if (counter == 0) {
                            string in = decodeString(s.substr(k+1, j-(k+1)));
                            for (int i = 0; i < theNum; ++i) {
                                ret += in;
                            }
                            i = j;
                            break;
                        } else {
                            counter --;
                        }
                    }
                }
            } else {
                ret.push_back(s[i]);
            }
        }
        return ret;
    }
};