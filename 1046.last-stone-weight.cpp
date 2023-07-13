/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stones_pq;
        for (size_t i = 0; i < stones.size(); ++i) {
            stones_pq.push(stones[i]);
        }

        while (stones_pq.size() > 1) {
            int heaviest = stones_pq.top();
            stones_pq.pop();
            int second_heaviest = stones_pq.top();
            stones_pq.pop();
            if (second_heaviest != heaviest) {
                second_heaviest = heaviest - second_heaviest;
                stones_pq.push(second_heaviest);
            }
        }

        if (stones_pq.empty()) {
            return 0;
        }
        return stones_pq.top();
    }
};
// @lc code=end
