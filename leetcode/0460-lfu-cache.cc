// https://leetcode.com/problems/lfu-cache/
// Hard
#include<unordered_map>
#include<list>
using namespace std;

class LFUCache {
    unordered_map<int, list<int>> freqLists;
    unordered_map<int, pair<int, int>> keyFreq;
    unordered_map<int, list<int>::iterator> keyIter; 
    int minFrequency = 0;
    int capacity;
public:
    LFUCache(int capacity): capacity{capacity} { }
    
    int get(int key) {

        if (keyFreq.find(key) == keyFreq.end()) return -1;
        int freq = keyFreq[key].first;
        int value = keyFreq[key].second;
        freqLists[freq].erase(keyIter[key]);
        keyFreq[key].first++;
        freqLists[freq+1].push_back(key);
        keyIter[key] = --freqLists[freq+1].end();
        if (freqLists[minFrequency].size() == 0) {
            minFrequency++;
        }

        return value;
    }
    
    void put(int key, int value) {
        if (keyFreq.find(key) != keyFreq.end()){
            int freq = keyFreq[key].first;
            freqLists[freq].erase(keyIter[key]);
            keyFreq[key].first++;
            keyFreq[key].second = value;
            freqLists[freq+1].push_back(key);
            keyIter[key] = --freqLists[freq+1].end();
            if (freqLists[minFrequency].size() == 0) {
                minFrequency++;
            }
        } else if (keyFreq.size() == capacity && capacity != 0) {
            keyIter.erase(freqLists[minFrequency].front());
            keyFreq.erase(freqLists[minFrequency].front());
            freqLists[minFrequency].pop_front();

            keyFreq[key].first = 1;
            keyFreq[key].second = value;
            freqLists[1].push_back(key);
            keyIter[key] = --freqLists[1].end();
            minFrequency = 1;
        } else if (capacity != 0) {
            keyFreq[key].first = 1;
            keyFreq[key].second = value;
            freqLists[1].push_back(key);
            keyIter[key] = --freqLists[1].end();
            minFrequency = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */