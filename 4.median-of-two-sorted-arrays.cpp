/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int total = nums1.size() + nums2.size();
        double result = 0.0;
        int low = 0, high = nums1.size();

        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = (total + 1) / 2 - mid1;

            int left1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int right1 = (mid1 < nums1.size()) ? nums1[mid1] : INT_MAX;
            int left2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int right2 = (mid2 < nums2.size()) ? nums2[mid2] : INT_MAX;

            if (left1 <= right2 && left2 <= right1) {
                if (total % 2 == 0) {
                    result = (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    result = max(left1, left2);
                }
                break;
            } else if (left1 > right2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }

        return result;
    }
};
// @lc code=end
