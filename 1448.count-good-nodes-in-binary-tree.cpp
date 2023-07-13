/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 */
// Definition for a binary tree node.
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
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
    int goodNodes(TreeNode *root) { return countNodes(root, INT_MIN); }

   private:
    int countNodes(TreeNode *root, int max_node) {
        if (!root) {
            return 0;
        }

        int good = 0;
        if (root->val >= max_node) {
            good = 1;
        }

        max_node = max(root->val, max_node);

        int left = countNodes(root->left, max_node);
        int right = countNodes(root->right, max_node);
        return good + left + right;
    }
};
// @lc code=end
