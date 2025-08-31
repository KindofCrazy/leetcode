/*
 * @lc app=leetcode.cn id=624 lang=cpp
 *
 * [624] 数组列表中的最大距离
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int minNum = arrays[0][0], maxNum = arrays[0][0];
        for (int i = 0; i < arrays.size(); i++) {
            auto array = arrays[i];
            int arrayMin = *min_element(array.begin(), array.end());
            int arrayMax = *max_element(array.begin(), array.end());
            int maxDis = max(abs(arrayMin - maxNum), abs(arrayMax - minNum));
            if (i > 0) ans = max(ans, maxDis);

            minNum = min(minNum, arrayMin);
            maxNum = max(maxNum, arrayMax);
        }

        return ans;
    }
};
// @lc code=end

