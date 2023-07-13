/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */
#include <iostream>
#include <utility>
using namespace std;
// @lc code=start

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right)
//         : val(x), left(left), right(right) {}
// };

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode *root) {
        int max_diameter = 0;
        dfs(root, max_diameter);
        return max_diameter;
    }

   private:
    int dfs(TreeNode *root, int &max_diameter) {
        if (!root) {
            return 0;
        }

        int left = dfs(root->left, max_diameter);
        int right = dfs(root->right, max_diameter);

        max_diameter = max(max_diameter, left + right);
        return 1 + max(left, right);
    }
};
// @lc code=end
