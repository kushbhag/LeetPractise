#include<vector>
#include<iostream>
#include<climits>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<sstream>
using namespace std;

void convert(unordered_map<int, string>&dic, vector<string>& v, int know, int find) {
    for (int l = 0; l < v.size(); ++l) {
        int j = 0;
        string temp = dic[know];
        string s = v[l];
        for (int i = 0; i < s.length() && j < temp.length(); ++i) {
            if (temp[j] == s[i]) {
                ++j;
            }
        }
        if (j >= temp.length()) {
            dic[find] = s;
            v.erase(v.begin() + l);
            break;
        }
    }
}

int main() {
    long count = 0, n=0;
    long maxNum = LONG_MIN, minNum = LONG_MAX;
    string input;
    // cout << input << endl;
    // vector<long> v;
    while(getline(cin, input)) { 
        stringstream ss (input);
        getline(ss, input, '|');
        unordered_map<int, string> dic;
        stringstream ss2 (input);
        vector<vector<string>> v (2);
        int len = 0;
        while (ss2 >> input) {
            len = input.length();
            sort(input.begin(), input.end());
            if (len == 2) dic[1] = input;
            else if (len == 4) dic[4] = input;
            else if (len == 7) dic[8] = input;
            else if (len == 3) dic[7] = input;
            else if (len == 5) v[1].push_back(input);
            else if (len == 6) v[0].push_back(input);
        }
        convert(dic, v[1], 1, 3);
        for (int l = 0; l < v[1].size(); ++l) {
            int j = 0;
            string temp = dic[4];
            string s = v[1][l];
            int i = 0;
            for (; i < s.length() && j < temp.length();) {
                if (temp[j] == s[i]) {
                    ++i;
                } else if (temp[j] < s[i]) {
                    ++j;
                } else {
                    ++i;
                }
            }
            cout << temp << ' ' << s << ' ';
            if (i >= 4) {
                dic[5] = s;
                v[1].erase(v[1].begin() + l);
                break;
            }
        }
        cout << endl;
        // if (v[1].size() != 1) throw 1;
        dic[2] = v[1].back();

        convert(dic, v[0], 4, 9);
        // if (v[0].size() != 2) throw 1;
        convert(dic, v[0], 7, 0);
        // if (v[0].size() != 1) throw 1;
        dic[6] = v[0].back();
        
        
        unordered_map<string, int> m;
        for (pair<int, string> p: dic) {
            cout << p.first << ' ';
            m[p.second] = p.first;
        }
        cout << endl;
        // if (m.size() != 10) throw 1;

        getline(ss, input);
        stringstream ss1 (input);
        long n = 0;
        while (ss1 >> input) {
            n *= 10;
            sort(input.begin(), input.end());
            // cout << input << ' ' << m[input] << ' ';
            n += m[input];
        }
        // cout << endl;
        // cout << n << endl;
        count += n;
        // ++n;
    }
    cout << count << endl;
}