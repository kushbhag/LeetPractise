// https://leetcode.com/problems/candy-crush/
// Locked
#include<string>
#include<iostream>

using namespace std;
string candyCrush(string s) {
    //cout << s <<  endl;
    int len = s.length();
    int currLen = 1;
    for (int i = 1; i < len; ++i) {
        if (s[i] == s[i-1]) {
            ++currLen;
        } else if (currLen >= 3) {
            s = s.substr(0,i-currLen) + s.substr(i, len);
            return candyCrush(s);
        } else {
            currLen = 1;
        }
    }
    if (currLen >= 3) {
        s = s.substr(0,len-currLen);
    }
    return s;
}

int main(){
    cout << candyCrush("aaabbbcccd") << endl;
    cout << candyCrush("aabbbacccd") << endl;
    cout << candyCrush("aabbccddeeedcba") << endl;
    cout << candyCrush("aaabbbc") << endl;
    cout << candyCrush("aaabbbacd") << endl;
    cout << candyCrush("dddabbbbaccccaax") << endl;
    cout << candyCrush("abcdefff") << endl;
}