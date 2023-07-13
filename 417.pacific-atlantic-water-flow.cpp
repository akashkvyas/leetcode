/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> reaches_pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> reaches_atlantic(heights.size(), vector<bool>(heights[0].size(), false));

        for (int i = 0; i < heights.size(); ++i) {
            dfs(heights, reaches_pacific, INT_MIN, i, 0);
            dfs(heights, reaches_atlantic, INT_MIN, i, heights[0].size() - 1);
        }

        for (int j = 0; j < heights[0].size(); ++j) {
            dfs(heights, reaches_pacific, INT_MIN, 0, j);
            dfs(heights, reaches_atlantic, INT_MIN, heights.size() - 1, j);
        }

        vector<vector<int>> result;
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = 0; j < heights[0].size(); ++j) {
                if (reaches_pacific[i][j] && reaches_atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

   private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int prev, int i, int j) {
        if (i < 0 || j < 0 || i == heights.size() || j == heights[0].size()) {
            return;
        }

        if (prev > heights[i][j] || visited[i][j]) {
            return;
        }

        visited[i][j] = true;

        dfs(heights, visited, heights[i][j], i + 1, j);
        dfs(heights, visited, heights[i][j], i - 1, j);
        dfs(heights, visited, heights[i][j], i, j + 1);
        dfs(heights, visited, heights[i][j], i, j - 1);
    }
};
// @lc code=end
