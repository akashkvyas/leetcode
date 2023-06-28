/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxes;
        for (int i = 0; i < k; ++i) {
            while (!maxes.empty() && nums[maxes.back()] < nums[i]) {
                maxes.pop_back();
            }
            maxes.push_back(i);
        }

        vector<int> result;
        result.push_back(nums[maxes.front()]);
        int end = k;
        for (int start = 1; start < nums.size() - k + 1; ++start) {
            while (!maxes.empty() && maxes.front() < start) {
                maxes.pop_front();
            }
            while (!maxes.empty() && nums[maxes.back()] < nums[end]) {
                maxes.pop_back();
            }
            maxes.push_back(end);
            result.push_back(nums[maxes.front()]);
            ++end;
        }
        return result;
    }
};
// @lc code=end
