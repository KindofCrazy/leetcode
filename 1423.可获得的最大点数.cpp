/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), length = n-k;

        long long totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if (length == 0) return totalSum;
        long long minSum = LONG_MAX, sum = 0;
        for (int i = 0; i < length - 1; i++) {
            sum += cardPoints[i];
        }
        for (int left = 0, right = length - 1; right < n; left++, right++) {
            sum += cardPoints[right];
            minSum = min(minSum ,sum);
            sum -= cardPoints[left];
        }

        return totalSum - minSum;
    }
};
// @lc code=end

