/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        k = k % n;
        if (k == 0) return;
        for(int start = 0; count < n; start++) {
            int pre_value = nums[start];
            int current = (start + k) % n;
            while(current != start) {
                swap(pre_value, nums[current]);
                current = (current + k) % n;
                count++;
            }
            swap(pre_value, nums[current]);
            count++;
        }
    }
};
// @lc code=end

