// https://leetcode.com/problems/subdomain-visit-count/
// Easy
// Mock

#include<vector>
#include<unordered_map>
#include<sstream>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        string temp, count;
        int tempLen, currLen, countInt;
        for (string& s: cpdomains) {
            stringstream ss (s);
            getline(ss, count, ' ');
            getline(ss, temp);
            countInt = stoi(count);
            tempLen = temp.length();
            currLen = 0;
            for (int i = 0; i < tempLen; ++i) {
                //cout << temp[i-currLen] << ' ' << i-currLen << endl;
                if (temp[i-currLen] == '.' || i+1 == tempLen) {
                    m[temp] += countInt;
                    temp.erase(0,i-currLen+1);
                    currLen = i + 1;
                }
            }
        }
        vector<string> ret;
        for (auto& p: m) {
            ret.push_back(to_string(p.second) + " " + p.first);
        }
        return ret;
    }
};