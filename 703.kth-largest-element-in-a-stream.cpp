/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// @lc code=start
class KthLargest {
   public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (size_t i = 0; i < nums.size(); ++i) {
            nums_pq.push(nums[i]);
        }
        while (nums_pq.size() > k) {
            nums_pq.pop();
        }
    }

    int add(int val) {
        nums_pq.push(val);
        if (nums_pq.size() > k) {
            nums_pq.pop();
        }
        return nums_pq.top();
    }

   private:
    int k;
    priority_queue<int, vector<int>, greater<int>> nums_pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
