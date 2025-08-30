/*
 * @lc app=leetcode.cn id=3143 lang=cpp
 *
 * [3143] 正方形中的最多点数
 */

// @lc code=start
class Solution {
public:
    bool inSquare(vector<int> point, int halfLength) {
        return abs(point[0]) <= halfLength && abs(point[1]) <= halfLength;
    }

    bool check(vector<vector<int>>& points, string s, int halfLength) {
        unordered_set<char> occ;
        for (int i = 0; i < s.size(); i++) {
            if (inSquare(points[i], halfLength)) {
                if (occ.count(s[i])) {
                    return false;
                } else {
                    occ.insert(s[i]);
                }
            }
        }

        return true;
    }

    int binarySearch(vector<vector<int>>& points, string s) {
        int maxHalfLength = 0;
        for (vector<int> p: points) {
            maxHalfLength = max(maxHalfLength, abs(p[0]));
            maxHalfLength = max(maxHalfLength, abs(p[1]));
        } 

        long long left = 0, right = (long long) maxHalfLength;
        while (left <= right) {
            long long mid = left + ((right - left) >> 1);
            if (check(points, s, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }

    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        long long halfLength = binarySearch(points, s);
        int ans = 0;
        for (auto point: points) {
            ans += inSquare(point, halfLength);
        }

        return ans;
    }
};
// @lc code=end

