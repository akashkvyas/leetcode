/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> s_count;
        unordered_map<char, int> t_count;
        for (size_t i = 0; i < s.size(); ++i) {
            ++s_count[s[i]];
            ++t_count[t[i]];
        }

        for (auto s_pair : s_count) {
            if (s_pair.second != t_count[s_pair.first]) return false;
        }
        return true;
    }
};
// @lc code=end