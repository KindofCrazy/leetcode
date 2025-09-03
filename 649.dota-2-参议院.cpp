/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        vector<int> valid(senate.size(), true);
        for (int i = 0; i < senate.size(); i++) {
            if (senate[i] == 'R') {
                r.push(i);
            } else {
                d.push(i);
            }
        } 

        int n = senate.size();
        while (!r.empty() && !d.empty()) {
            if (r.front() < d.front()) {
                r.push(r.front() + n);
            } else {
                d.push(d.front() + n);
            }
            r.pop();
            d.pop();
        }

        if (r.size() == 0) return "Dire";
        else if (d.size() == 0) return "Radiant";
        return "";
    }
};
// @lc code=end

