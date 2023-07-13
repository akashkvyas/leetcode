/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }

        return max(robHelper(nums, 0, nums.size() - 2), robHelper(nums, 1, nums.size() - 1));
    }

   private:
    int robHelper(vector<int>& nums, int start, int end) {
        int spaced = 0, adjacent = 0;
        for (int i = start; i <= end; ++i) {
            int curr = max(spaced + nums[i], adjacent);
            spaced = adjacent;
            adjacent = curr;
        }
        return adjacent;
    }
};
// @lc code=end
