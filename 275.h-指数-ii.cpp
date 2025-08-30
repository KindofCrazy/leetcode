/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& citations, int hIndex) {
        return citations[citations.size() - hIndex] >= hIndex;
    }

    int binarySearch(vector<int>& citations) {
        int left = 1, right = citations.size();
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (check(citations, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }

    int hIndex(vector<int>& citations) {
        return binarySearch(citations);
    }
};
// @lc code=end

