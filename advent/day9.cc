#include<vector>
#include<iostream>
#include<climits>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<sstream>
#include<queue>
using namespace std;

vector<pair<int, int>> d = {{-1, -1}, {-1, 0}, {0, -1},
                            {1, 1}, {1, 0}, {0, 1},
                            {1, -1}, {-1, 1}};
vector<pair<int, int>> d2 = {{-1, 0}, {0, -1},
                            {1, 0}, {0, 1}};
vector<vector<bool>> visited;
int r, c;
int dfs (int last, int i, int j, vector<vector<int>>& v) {
    if (i < 0 || i >= r || j < 0 || j >= c || v[i][j] == 9 || v[i][j] <= last || visited[i][j])  {
        return 0;
    }
    int size = 1;
    visited[i][j] = true;
    for (pair<int, int>& p: d2) {
        size += dfs(v[i][j], i+p.first, j + p.second, v);
    }
    return size;
}
int main() {
    vector<vector<int>> v;
    string input;
    while (getline(cin, input)) {
        vector<int> t;
        vector<bool> te;
        for (char &c: input) {
            if (isalnum(c)) {
                t.push_back(c-'0');
                te.push_back(false);
            }
        }
        v.push_back(t);
        visited.push_back(te);
    }
    r = v.size();
    c = v[0].size();
    int count = 0;
    vector<pair<int, int>> low;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            bool check = true;
            // cout << v[i][j] << ' ';
            for (pair<int, int> &p: d) {
                if (i + p.first < r && i + p.first >= 0 &&
                    j + p.second < c && j + p.second >= 0) {
                    if (v[i][j] >= v[i+p.first][j+p.second]) {
                        check = false;
                        break;
                    }
                }
            }
            if (check) {
                low.push_back({i, j});
                // count += v[i][j] + 1;
            }
        }
        // cout << endl;
    }

    int s = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (pair<int, int> &p: low) {
        int temp = dfs(INT_MIN, p.first, p.second, v);
        cout << temp << endl;
        if (pq.size() >= 3 && temp > pq.top()) {
            pq.pop();
            pq.push(temp);
        } else if (pq.size() < 3) {
            pq.push(temp);
        }
    }
    cout << "SIZE: " << pq.size() << endl;
    while (!pq.empty()) {
        s*= pq.top();
        pq.pop();
    }
    cout << s << endl;
}