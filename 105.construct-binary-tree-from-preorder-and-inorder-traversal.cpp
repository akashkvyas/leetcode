/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int root_index = 0;
        return buildTreeHelper(preorder, inorder, root_index, 0, inorder.size() - 1);
    }

private:
    TreeNode* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int &root_index, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[root_index]);

        int inorder_index = -1;
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == preorder[root_index]) {
                inorder_index = i;
            }
        }
        ++root_index;

        root->left = buildTreeHelper(preorder, inorder, root_index, start, inorder_index - 1);
        root->right = buildTreeHelper(preorder, inorder, root_index, inorder_index + 1, end);

        return root;
    }
};
// @lc code=end
