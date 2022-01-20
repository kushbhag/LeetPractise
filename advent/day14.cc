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

unordered_map<string, string> m;
unordered_map<string, long> counts;
unordered_set<string> u;

int main() {
    string input, n1, n2;
    vector<vector<int>> v;
    int x;
    string starting;
    getline(cin, starting);
    while (getline(cin, input)) {
        stringstream ss (input);
        m[input.substr(0,2)] = input.substr(6, 1);
    }
    vector<long> co (26, 0);
    for (int i = 0; i < starting.length()-1; ++i) {
        co[starting[i] - 'A']++;
        counts[starting.substr(i, 2)]++;
    }
    for (int k =0; k < 40; ++k) {
        unordered_map<string, long> tempCounts;
        for (pair<string, long> p: counts) {
            if (m.find(p.first) != m.end()) {
                string s = p.first.substr(0, 1) + m[p.first];
                tempCounts[s] += p.second;
                co[s[1] - 'A'] += p.second;
                s = m[p.first] + p.first[1];
                tempCounts[s] += p.second;
            }
        }
        counts = tempCounts;
    }
    int most = INT_MIN, least = INT_MAX;
    sort(co.begin(), co.end());
    int i =0;
    for (; i < 26; ++i) {
        if (co[i] > 0) break;
    }
    cout << co.back() << endl;
    cout << co.back() - co[i] << endl;
}