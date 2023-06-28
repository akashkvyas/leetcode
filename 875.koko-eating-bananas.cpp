/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_speed = *max_element(piles.begin(), piles.end());
        int low = 1, high = min_speed;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            cout << mid << " ";
            if (valid_speed(piles, mid, h)) {
                min_speed = min(mid, min_speed);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return min_speed;
    }

   private:
    bool valid_speed(vector<int>& piles, int k, int h) {
        int h_used = 0;
        for (size_t i = 0; i < piles.size(); ++i) {
            h_used += (piles[i] / k);
            if (piles[i] % k != 0) {
                ++h_used;
            }
            if (h_used > h) {
                return false;
            }
        }
        return h_used <= h;
    }
};
// @lc code=end
