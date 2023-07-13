/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    int rob(vector<int>& nums) {
        int spaced = 0, adjacent = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            int curr = max(nums[i] + spaced, adjacent);
            spaced = adjacent;
            adjacent = curr;
        }
        return adjacent;
    }
};
// @lc code=end
