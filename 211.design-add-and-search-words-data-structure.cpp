/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */
#include <iostream>
#include <unordered_map>
using namespace std;
// @lc code=start
class TrieNode {
   public:
    unordered_map<char, TrieNode*> children;
    bool is_end = false;
};

class WordDictionary {
   public:
    WordDictionary() { start = new TrieNode(); }

    void addWord(string word) {
        TrieNode* curr = start;
        for (size_t i = 0; i < word.size(); ++i) {
            if (!curr->children[word[i]]) {
                curr->children[word[i]] = new TrieNode();
            }
            curr = curr->children[word[i]];
        }
        curr->is_end = true;
    }

    bool search(string word) { return searchHelper(word, 0, start); }

   private:
    TrieNode* start;

    bool searchHelper(string word, int index, TrieNode* curr) {
        if (!curr) {
            return false;
        }

        if (index == word.size()) {
            return curr->is_end;
        }

        if (word[index] != '.') {
            return searchHelper(word, index + 1, curr->children[word[index]]);
        }

        for (auto child : curr->children) {
            if (searchHelper(word, index + 1, child.second)) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
