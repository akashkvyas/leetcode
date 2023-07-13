/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */
#include <iostream>
#include <vector>
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
    int kthSmallest(TreeNode *root, int k) {
        vector<int> result;
        inorder_traverse(root, result);
        return result[k - 1];
    }

   private:
    void inorder_traverse(TreeNode *root, vector<int> &result) {
        if (!root) {
            return;
        }
        inorder_traverse(root->left, result);
        result.push_back(root->val);
        inorder_traverse(root->right, result);
    }
};
// @lc code=end
