/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */
// Definition for singly-linked list.
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// @lc code=start
class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        ListNode* temp = nullptr;

        int count = k;

        while (curr) {
            if (count > 1) {
                temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;

                count--;
            } else {
                prev = curr;
                curr = curr->next;
                count = k;

                ListNode* end = curr;
                for (int i = 0; i < k; i++) {
                    if (!end) {
                        return dummy->next;
                    }
                    end = end->next;
                }
            }
        }

        return dummy->next;
    }
};
// @lc code=end
