/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int min_num = numeric_limits<int>::max();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            min_num = min(nums[mid], min_num);
            if (nums[mid] > nums[nums.size() - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return min_num;
    }
};
// @lc code=end
