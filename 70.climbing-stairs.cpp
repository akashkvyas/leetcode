/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        int one_behind = 2, two_behind = 1;
        for (int i = 2; i < n; ++i) {
            int curr = one_behind + two_behind;
            two_behind = one_behind;
            one_behind = curr;
        }
        return one_behind;
    }
};
// @lc code=end
