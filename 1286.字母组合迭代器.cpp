/*
 * @lc app=leetcode.cn id=1286 lang=cpp
 *
 * [1286] 字母组合迭代器
 */

// @lc code=start
class CombinationIterator {
public:

    string com;
    vector<string> combinations;
    int now = -1;

    void dfs(string characters, int combinationLength, int idx) {
        if (com.size() == combinationLength) {
            combinations.emplace_back(com);
            return;
        }

        if (com.size() + (characters.size()-idx) < combinationLength) {
            return;
        }

        for (int i = idx; i < characters.size(); i++) {
            com.push_back(characters[i]);
            dfs(characters, combinationLength, i+1);
            com.pop_back();
        }
    }

    CombinationIterator(string characters, int combinationLength) {
        dfs(characters, combinationLength, 0);
    }
    
    string next() {
        return combinations[++now];
    }
    
    bool hasNext() {
        return now < (int)combinations.size()-1;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

