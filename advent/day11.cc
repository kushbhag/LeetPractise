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

vector<pair<int, int>> d = {{-1, -1}, {-1, 0}, {0, -1},
                            {1, 1}, {1, 0}, {0, 1},
                            {1, -1}, {-1, 1}};

void dfs(int r, int c, vector<vector<int>> &v, vector<vector<bool>>& checked) {
    if (r < 0 || c < 0 || r >= v.size() || c >= v[0].size() || checked[r][c]) return;
    ++v[r][c];
    if (v[r][c] > 9) {
        checked[r][c] = true;
        // cout << r << ' ' << c << endl;
        for (pair<int, int> &p: d) {
            dfs(r+p.first, c+p.second, v, checked);
        }
    }
}

int main() {
    string input;
    vector<vector<int>> v;
    while (getline(cin, input)) {
        vector<int> t;
        for (int i = 0; i < input.length()-1; ++i) {
            t.push_back(input[i]-'0');
        }
        v.push_back(t);
    }
    int count = 0;
    int row = v.size(), col = v[0].size();
    for (int i = 0; i < 1000; ++i) {
        vector<vector<bool>> checked (row, vector<bool> (col, false));
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                dfs(r, c, v, checked);
            }
        }
        int co = 0;
        for (int r = 0; r < v.size(); ++r) {
            for (int c = 0; c < v[0].size(); ++c) {
                if (v[r][c] > 9) {
                    ++co;
                    v[r][c] = 0;
                }
            }
        }
        if (co == row*col) {
            cout << i << endl;
            return 1;
        }
    }
}