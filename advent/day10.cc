#include<vector>
#include<iostream>
#include<climits>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<sstream>
#include<queue>
#include<algorithm>
using namespace std;


int main() {
    string input;
    unordered_map<char, int> m;
    m[')'] = 1;
    m[']'] = 2;
    m['}'] = 3;
    m['>'] = 4;
    int count = 0;
    vector<long> ch;
    while (getline(cin, input)) {
        vector<char> v;
        bool good = true;
        for (int i = 0; i < input.length()-1; ++i) {
            char c = input[i];
            if (c == '(') v.push_back(')');
            else if (c == '[') v.push_back(']');
            else if (c == '{') v.push_back('}');
            else if (c == '<') v.push_back('>');
            else {
                if (c != '\n' && v.back() != c) {
                    // cout << v.back() << '|' << c << endl;
                    good = false;
                    break;
                }
                v.pop_back();
            }
        }
        long score = 0;
        if (good) {
            while (!v.empty()) {
                score = (score*5) + m[v.back()];
                v.pop_back();
            }
            cout << score << endl;
            ch.push_back(score);
        }
    }
    sort(ch.begin(), ch.end());
    cout << ch[ch.size()/2] << endl;

}