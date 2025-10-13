/*
 * @lc app=leetcode.cn id=2273 lang=cpp
 *
 * [2273] 移除字母异位词后的结果数组
 */

// @lc code=start
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {        
        int i = 1;
        while (i < words.size()) {
            string key1 = words[i-1], key2 = words[i];
            sort(key1.begin(), key1.end());
            sort(key2.begin(), key2.end());
            if (key1 == key2) {
                words.erase(words.begin()+i);
            } else {
                i++;
            }
        }

        return words;
    }
};
// @lc code=end

