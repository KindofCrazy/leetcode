/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 *
 * [2090] 半径为 k 的子数组平均值
 */

// @lc code=start
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(-1);
            if (ans.size() >= n) return ans;
        }

        long long sum = 0;
        for (int i = 0; i < 2*k && i < n; i++) {
            sum += nums[i];
        }
        for (int left = 0, right=2*k; right < n; left++, right++) {
            sum += nums[right];
            ans.push_back(sum / (2*k+1));
            if (ans.size() >= n) return ans;
            sum -= nums[left];
        }

        for (int i = 0; i < k; i++) {
            ans.push_back(-1);
            if (ans.size() >= n) return ans;
        }

        return ans;
    }
};
// @lc code=end

