/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> result;
        vector<int> level;

        queue<pair<TreeNode *, int>> bfs;
        bfs.push({root, 0});

        int curr_level = 0;
        while (!bfs.empty()) {
            pair<TreeNode *, int> curr = bfs.front();
            bfs.pop();

            if (curr.second != curr_level) {
                result.push_back(level);
                level = {};
                curr_level = curr.second;
            }

            level.push_back(curr.first->val);

            if (curr.first->left) {
                bfs.push({curr.first->left, curr_level + 1});
            }
            if (curr.first->right) {
                bfs.push({curr.first->right, curr_level + 1});
            }
        }
        result.push_back(level);
        return result;
    }
};
// @lc code=end
