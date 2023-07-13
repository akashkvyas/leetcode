/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class ComparePoints {
   public:
    bool operator()(vector<int> &point1, vector<int> &point2) {
        double distance1 = sqrt(pow(point1[0], 2) + pow(point1[1], 2));
        double distance2 = sqrt(pow(point2[0], 2) + pow(point2[1], 2));
        return distance1 > distance2;
    }
};
class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, ComparePoints>
            points_pq;

        for (size_t i = 0; i < points.size(); ++i) {
            points_pq.push(points[i]);
        }

        vector<vector<int>> result;
        for (size_t i = 0; i < k; ++i) {
            result.push_back(points_pq.top());
            points_pq.pop();
        }

        return result;
    }
};
// @lc code=end
