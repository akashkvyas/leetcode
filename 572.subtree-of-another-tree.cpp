/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */
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
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (!root || !subRoot) {
            return false;
        }

        if (compare_trees(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

   private:
    bool compare_trees(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) {
            return true;
        }

        if (!root1 || !root2) {
            return false;
        }

        if (root1->val != root2->val) {
            return false;
        }

        return compare_trees(root1->left, root2->left) &&
               compare_trees(root1->right, root2->right);
    }
};
// @lc code=end
