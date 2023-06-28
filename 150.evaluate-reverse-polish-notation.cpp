/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        int operand_1, operand_2;
        for (size_t i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                operand_2 = stack.top();
                stack.pop();
                operand_1 = stack.top();
                stack.pop();
                stack.push(operand_1 + operand_2);
            } else if (tokens[i] == "-") {
                operand_2 = stack.top();
                stack.pop();
                operand_1 = stack.top();
                stack.pop();
                stack.push(operand_1 - operand_2);
            } else if (tokens[i] == "*") {
                operand_2 = stack.top();
                stack.pop();
                operand_1 = stack.top();
                stack.pop();
                stack.push(operand_1 * operand_2);
            } else if (tokens[i] == "/") {
                operand_2 = stack.top();
                stack.pop();
                operand_1 = stack.top();
                stack.pop();
                stack.push(operand_1 / operand_2);
            } else {
                stack.push(stoi(tokens[i]));
            }
        }
        return stack.top();
    }
};
// @lc code=end
