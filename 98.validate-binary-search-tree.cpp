/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode *root) {
        return validateBST(root, LONG_MIN, LONG_MAX);
    }

   private:
    bool validateBST(TreeNode *root, long min, long max) {
        if (!root) {
            return true;
        }
        if (root->val > min && root->val < max) {
            return validateBST(root->left, min, root->val) &&
                   validateBST(root->right, root->val, max);
        }
        return false;
    }
};
// @lc code=end
