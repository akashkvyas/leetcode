/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> end_times;
        for (size_t i = 0; i < position.size(); ++i) {
            double time = (double)(target - position[i]) / speed[i];
            end_times.push_back({position[i], time});
        }
        sort(end_times.begin(), end_times.end());

        int fleets = 0;
        double max_time = -1;
        for (int i = end_times.size() - 1; i >= 0; --i) {
            if (end_times[i].second > max_time) {
                max_time = end_times[i].second;
                ++fleets;
            }
        }

        return fleets;
    }
};
// @lc code=end
