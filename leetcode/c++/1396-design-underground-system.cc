// https://leetcode.com/problems/design-underground-system/
// Medium
#include<string>
#include<unordered_map>
#include<utility>
using namespace std;

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> travelling;
    unordered_map<string, pair<int, int>> averages;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        travelling[id] = pair<string, int> {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> p = travelling[id];
        string startEnd = p.first + " " + stationName;
        int timeToTravel = t - p.second;
        averages[startEnd].first += timeToTravel;
        averages[startEnd].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string startEnd = startStation + " " + endStation;
        if (averages.find(startEnd) == averages.end()) {
            return 0;
        }
        return (double)(averages[startEnd].first / averages[startEnd].second);
    }
};