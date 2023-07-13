/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */
// Definition for a binary tree node.
#include <iostream>
#include <queue>
#include <vector>
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
    vector<int> rightSideView(TreeNode *root) {
        if (!root) {
            return {};
        }

        vector<int> result;

        queue<TreeNode *> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            size_t level_size = bfs.size();
            TreeNode *curr = nullptr;
            for (size_t i = 0; i < level_size; ++i) {
                curr = bfs.front();
                bfs.pop();
                if (curr->left) {
                    bfs.push(curr->left);
                }
                if (curr->right) {
                    bfs.push(curr->right);
                }
            }
            result.push_back(curr->val);
        }

        return result;
    }
};
// @lc code=end
