/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
// @lc code=start

class Solution {
   public:
    int maxPathSum(TreeNode *root) {
        int max_sum = INT_MIN;
        maxPathSumHelper(root, max_sum);
        return max_sum;
    }

   private:
    int maxPathSumHelper(TreeNode *root, int &max_sum) {
        if (!root) {
            return 0;
        }

        int max_left = max(maxPathSumHelper(root->left, max_sum), 0);
        int max_right = max(maxPathSumHelper(root->right, max_sum), 0);

        max_sum = max(max_sum, max_left + root->val + max_right);

        return root->val + max(max_left, max_right);
    }
};
// @lc code=end
