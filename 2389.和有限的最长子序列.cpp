/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 *
 * [2389] 和有限的最长子序列
 */

// @lc code=start
class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
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

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        vector<int> sum;
        int tmpSum = 0;
        for (int num: nums) {
            tmpSum += num;
            sum.push_back(tmpSum);
        }

        vector<int> ans;
        for (int query: queries) {
            int pos = binarySearch(sum, query+1);
            ans.push_back(pos);
        }

        return ans;
    }
};
// @lc code=end

