/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low_row = 0, high_row = matrix.size() - 1;
        int mid;
        while (low_row <= high_row) {
            mid = low_row + ((high_row - low_row) / 2);
            if (matrix[mid][0] < target && mid < matrix.size() - 1 &&
                matrix[mid + 1][0] > target) {
                break;
            } else if (matrix[mid][0] < target) {
                low_row = mid + 1;
            } else if (matrix[mid][0] > target) {
                high_row = mid - 1;
            } else {
                return true;
            }
        }

        auto lb = lower_bound(matrix[mid].begin(), matrix[mid].end(), target);
        int row_index = lb - matrix[mid].begin();
        if (row_index < matrix[mid].size() &&
            matrix[mid][row_index] == target) {
            return true;
        }

        return false;
    }
};
// @lc code=end
