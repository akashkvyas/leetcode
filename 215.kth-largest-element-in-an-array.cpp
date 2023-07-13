/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> nums_pq;
        for (size_t i = 0; i < nums.size(); ++i) {
            nums_pq.push(nums[i]);
        }

        while (nums_pq.size() > k) {
            nums_pq.pop();
        }

        return nums_pq.top();
    }
};
// @lc code=end
