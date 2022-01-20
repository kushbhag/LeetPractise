// https://leetcode.com/problems/online-stock-span/
// Medium
#include<vector>
#include<queue>
#include<utility>
using  namespace std;

class StockSpanner {
    vector<pair<int, int>> s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while (!s.empty() && s.back().first <= price) {
            res += s.back().second;
            s.pop_back();
        }
        s.push_back({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */