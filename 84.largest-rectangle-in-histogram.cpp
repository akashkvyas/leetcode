/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stack;
        int max_area = 0;

        for (int i = 0; i < heights.size(); ++i) {
            int start = i;

            while (!stack.empty() && stack.top().second > heights[i]) {
                start = stack.top().first;
                max_area = max((i - start) * stack.top().second, max_area);
                stack.pop();
            }

            stack.push({start, heights[i]});
        }

        while (!stack.empty()) {
            int area =
                (heights.size() - stack.top().first) * stack.top().second;
            max_area = max(area, max_area);
            stack.pop();
        }

        return max_area;
    }
};
// @lc code=end
