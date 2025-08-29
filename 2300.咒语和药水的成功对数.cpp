/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

// @lc code=start
class Solution {
public:
    int binarySearch(vector<int>& nums, double target) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int spell: spells) {
            double target = (double) success / spell;
            int pos = binarySearch(potions, target);
            ans.push_back(potions.size() - pos);
        }

        return ans;
    }
};
// @lc code=end

