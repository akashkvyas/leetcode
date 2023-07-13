/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> nums_count;
        for (size_t i = 0; i < nums.size(); ++i) {
            ++nums_count[nums[i]];
            if (nums_count[nums[i]] > 1) return true;
        }
        return false;
    }
};
// @lc code=end