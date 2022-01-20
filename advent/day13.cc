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
unordered_set<string> u;

int main() {
    string input, n1, n2;
    vector<pair<int, int>> pv;
    vector<pair<int, int>> fold;
    int x, maxX = INT_MIN, maxY=  INT_MIN;
    while (getline(cin, input)) {
        stringstream ss (input);
        if (input.substr(0, 4) == "fold") {
            ss >> n1 >> n2;
            getline(ss, input, '=');
            // cout << "NO" << endl;
            if (input == " y") {
                // cout << "HERE" << endl;
                ss >> input;
                // cout << input << endl;
                fold.push_back({0, stoi(input)});
            } else {
                ss >> input;
                fold.push_back({1, stoi(input)});
            }

            continue;
        }
        // cout << "HERE" <<
        getline(ss, n1, ',');
        ss >> x;
        pv.push_back({stoi(n1), x});
        maxX = max(maxX, stoi(n1));
        maxY = max(maxY, x);
    }
    vector<vector<bool>> v (maxX+1, vector<bool> (maxY+1, false));
    for (pair<int, int>& p: pv) {
        v[p.first][p.second] = true;
    }
    cout << maxX << ' ' << maxY << endl;
    for (pair<int, int> &p: fold) {
        // pair<int, int> p = fold[k];
        cout << p.first << ' ' << p.second << endl;
        if (p.first == 0) {
            vector<vector<bool>> v1 (v.size(), vector<bool> (p.second, false));
            for (int i = 0; i < v.size(); ++i) {
                for (int j = 0; j < v[0].size(); ++j) {
                    if (j == p.second) continue;
                    if (j > p.second) {
                        v1[i][p.second+(p.second-j)] = v[i][j] || v1[i][p.second+(p.second-j)];
                    } else {
                        v1[i][j] = v[i][j];
                    }
                }
            }
            v = v1;
        } else {
            vector<vector<bool>> v1 (p.second, vector<bool> (v[0].size(), false));
            for (int i = 0; i < v.size(); ++i) {
                for (int j = 0; j < v[0].size(); ++j) {
                    if (i == p.second) continue;
                    // cout << i << ' ' << j << endl;
                    if (i > p.second) {
                        v1[p.second+(p.second-i)][j] = v[i][j] || v1[p.second+(p.second-i)][j];
                    } else {
                        v1[i][j] = v[i][j];
                    }
                }
            }
            v = v1;
        }
    }
    int count = 0;
    for (int i = v.size()-1; i >= 0; --i) {
        for (int j = 0; j < v[0].size(); ++j) {
            if (v[i][j] == 1) {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
    cout << count << endl;

}