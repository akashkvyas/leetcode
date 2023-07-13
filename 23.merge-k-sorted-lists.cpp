/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int num_lists = lists.size();
        if (num_lists == 0) {
            return nullptr;
        }
        while (num_lists > 1) {
            for (size_t i = 0; i < num_lists / 2; ++i) {
                lists[i] = merge_two_lists(lists[i], lists[num_lists - i - 1]);
            }
            num_lists = (num_lists + 1) / 2;
        }
        return lists.front();
    }

   private:
    ListNode* merge_two_lists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }

        if (list1->val <= list2->val) {
            list1->next = merge_two_lists(list1->next, list2);
            return list1;
        } else {
            list2->next = merge_two_lists(list1, list2->next);
            return list2;
        }
    }
};
// @lc code=end
