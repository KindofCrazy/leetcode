/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> points;
        for (string op: operations) {
            int sz = points.size();
            if (op == "+") {
                points.push_back(points[sz-2] + points[sz-1]);
            } else if (op == "D") {
                points.push_back(points[sz-1] * 2);
            } else if (op == "C") {
                points.pop_back();
            } else {
                points.push_back(stoi(op));
            }
        }

        return accumulate(points.begin(), points.end(), 0);
    }
};
// @lc code=end

