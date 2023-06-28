/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */
#include <stack>
using namespace std;
// @lc code=start
class MinStack {
   public:
    MinStack() {}

    void push(int val) {
        if (min_stack.empty()) {
            min_stack.push(val);
        } else {
            min_stack.push(min(val, min_stack.top()));
        }
        stack.push(val);
    }

    void pop() {
        stack.pop();
        min_stack.pop();
    }

    int top() { return stack.empty() ? -1 : stack.top(); }

    int getMin() { return stack.empty() ? -1 : min_stack.top(); }

   private:
    stack<int> min_stack;
    stack<int> stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
