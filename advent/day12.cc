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

unordered_map<string, unordered_set<string>> m;
unordered_set<string> small;
int cnt = 0;

void dfs(string s, unordered_map<string, int>& checked, string db) {
    if (small.find(s) != small.end() && checked[s] >= 2) {
        if (db.empty() && checked[s] <= 2) {
            db = s;
        } else {
            return;
        }
    }
    if (s == "end") {
        ++cnt;
        return;
    }
    // cout << s << endl;
    // if (small.find(s) != small.end()) return;
    for (string n: m[s]) {
        if (n == "start") continue;

        checked[n]++;
        dfs(n, checked, db);
        checked[n]--;
        // }
        // if ((small.find(n) != small.end() && checked.find(n) != checked.end() && sm) || n == "start") continue;
        // if (small.find(n) != small.end() && !sm && checked.find(n) == checked.end()) {
        //     checked.insert(n);
        //     dfs(n, checked, true);
        //     // dfs(n, checked, false);
        //     checked.erase(n);
        // } else {
        //     checked.insert(n);
        //     dfs(n, checked, sm);
        //     checked.erase(n);
        // }
    }
}

int main() {
    string input, n1, n2;
    vector<vector<int>> v;
    while (getline(cin, input)) {
        stringstream ss (input);
        getline(ss, n1, '-');
        ss >> n2;
        // cout << '|'<< n1 << '|' << n2<< '|' << endl;
        m[n1].insert(n2);
        m[n2].insert(n1);
    }
    for (pair<string, unordered_set<string>> p: m) {
        cout << '|'<< p.first << '|' << endl;
        for (string s: p.second) {
            cout << s << ' ';
        }
        cout << endl;
        if (islower(p.first[0])) {
            small.insert(p.first);
        }
    }
    unordered_map<string, int> checked;
    dfs("start", checked, "");
    cout << cnt << endl;
}