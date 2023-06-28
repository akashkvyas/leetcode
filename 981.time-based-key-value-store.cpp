/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class TimeMap {
   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) {
            return "";
        }

        int low = 0, high = map[key].size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (map[key][mid].second < timestamp) {
                low = mid + 1;
            } else if (map[key][mid].second > timestamp) {
                high = mid - 1;
            } else {
                return map[key][mid].first;
            }
        }

        if (high >= 0) {
            return map[key][high].first;
        }

        return "";
    }

   private:
    unordered_map<string, vector<pair<string, int>>> map;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
