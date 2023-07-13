/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class TrieNode {
   public:
    TrieNode() { is_end = false; }
    unordered_map<char, TrieNode*> children;
    bool is_end;
};

class Trie {
   public:
    Trie() { start = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = start;
        for (size_t i = 0; i < word.size(); ++i) {
            if (!curr->children[word[i]]) {
                curr->children[word[i]] = new TrieNode();
            }
            curr = curr->children[word[i]];
        }
        curr->is_end = true;
    }

    bool search(string word) {
        TrieNode* curr = start;
        for (size_t i = 0; i < word.size(); ++i) {
            if (!curr->children[word[i]]) {
                return false;
            }
            curr = curr->children[word[i]];
        }
        return curr->is_end;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = start;
        for (size_t i = 0; i < prefix.size(); ++i) {
            if (!curr->children[prefix[i]]) {
                return false;
            }
            curr = curr->children[prefix[i]];
        }
        return true;
    }

   private:
    TrieNode* start = nullptr;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
