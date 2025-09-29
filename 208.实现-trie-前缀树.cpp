/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    vector<Trie*> children;
    bool isend;

    Trie(): children(26), isend(false) {
        
    }
    
    void insert(string word) {
        Trie* node = this;
        for (char c: word) {
            if (!node->children[c-'a']) node->children[c-'a'] = new Trie();
            node = node->children[c-'a'];
        }
        node->isend = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char c: word) {
            if (!node->children[c-'a']) return false;
            node = node->children[c-'a'];
        }

        return node->isend;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c: prefix) {
            if (!node->children[c-'a']) return false;
            node = node->children[c-'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

