/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> subset;
        vector<vector<int>> result;
        subsets_helper(nums, 0, subset, result);
        return result;
    }

   private:
    void subsets_helper(vector<int> &nums, int start, vector<int> &subset,
                        vector<vector<int>> &result) {
        result.push_back(subset);
        for (int i = start; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            subsets_helper(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }
};
// @lc code=end
