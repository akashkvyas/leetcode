/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        encode(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream data_ss(data);
        return decode(data_ss);
    }

   private:
    void encode(TreeNode* root, string& result) {
        if (!root) {
            result += "N ";
            return;
        }

        result += to_string(root->val);
        result += " ";

        encode(root->left, result);
        encode(root->right, result);
    }

    TreeNode* decode(stringstream& data) {
        string val;
        data >> val;
        if (val == "N") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root->left = decode(data);
        root->right = decode(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
