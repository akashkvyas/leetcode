/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        vector<vector<int>> result;
        dfs(candidates, target, 0, 0, subset, result);
        return result;
    }

   private:
    void dfs(vector<int> &candidates, int target, int start, int sum,
             vector<int> &subset, vector<vector<int>> &result) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(subset);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            subset.push_back(candidates[i]);
            dfs(candidates, target, i, sum + candidates[i], subset, result);
            subset.pop_back();
        }
    }
};
// @lc code=end
