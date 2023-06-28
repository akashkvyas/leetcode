/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        generateCombination(n, 0, 0, "");
        return valid_parenthesis;
    }

   private:
    void generateCombination(int n, int open, int close, string str) {
        if (open == n && close == n) {
            valid_parenthesis.push_back(str);
            return;
        }

        if (open < n) {
            str += "(";
            generateCombination(n, open + 1, close, str);
            str.pop_back();
        }

        if (close < open) {
            str += ")";
            generateCombination(n, open, close + 1, str);
        }

        return;
    }
    vector<string> valid_parenthesis;
};
// @lc code=end