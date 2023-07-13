/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class TrieNode {
   public:
    unordered_map<char, TrieNode*> next;
    bool is_end = false;
};

class Solution {
   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* start = new TrieNode();
        for (size_t i = 0; i < words.size(); ++i) {
            TrieNode* curr = start;
            for (size_t j = 0; j < words[i].size(); ++j) {
                if (curr->next.find(words[i][j]) == curr->next.end()) {
                    curr->next[words[i][j]] = new TrieNode();
                }
                curr = curr->next[words[i][j]];
            }
            curr->is_end = true;
        }

        vector<string> result;
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[0].size(); ++j) {
                search(board, start, "", i, j, result);
            }
        }

        return result;
    }

   private:
    void search(vector<vector<char>>& board, TrieNode* curr, string word, int i, int j, vector<string>& result) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#' || !curr) {
            return;
        }

        if (curr->next.find(board[i][j]) == curr->next.end()) {
            return;
        }

        char letter = board[i][j];
        word += letter;
        curr = curr->next[letter];

        if (curr->is_end) {
            result.push_back(word);
            curr->is_end = false;
        }

        board[i][j] = '#';

        search(board, curr, word, i + 1, j, result);
        search(board, curr, word, i - 1, j, result);
        search(board, curr, word, i, j + 1, result);
        search(board, curr, word, i, j - 1, result);

        board[i][j] = letter;
    }
};
// @lc code=end
