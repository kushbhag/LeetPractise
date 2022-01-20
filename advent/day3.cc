#include<vector>
#include<iostream>
#include<climits>
#include <string>
using namespace std;

int main() {
    vector<int> v1 (12, 0);
    vector<int> v2 (12, 0);
    vector<string> all;
    string s;
    while (cin >> s) {
        all.push_back(s);
    }
    int index = 0;
    do {
        vector<string> vzero, vone;
        for (int i = 0; i < all.size(); ++i) {
            if (all[i][index] == '0') {
                v1[index]++;
                vzero.push_back(all[i]);
            } else {
                v2[index]++;
                vone.push_back(all[i]);
            }
        }
        cout << index << ' ' << (v1[index] > v2[index]) << ' ' << all.size() << endl;
        if (v1[index] <= v2[index]) {
            all = vzero;
        } else {
            all = vone;
        }
        cout << vzero.size() << ' ' << vone.size() << endl;
        // cout << index << ' ' << (v1[index] > v2[index]) << ' ' << all.size() << endl;
        ++index;
    } while (all.size() > 1 && index < 12);
    
    cout << index << endl;
    // cout << vone.size() << endl;
    // cout << vzero.size() << endl;
    cout << all.size() << endl;
    cout << all.back() << endl;
    // return count;
}