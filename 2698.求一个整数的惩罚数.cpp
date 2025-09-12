/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 *
 * [2698] 求一个整数的惩罚数
 */

// @lc code=start
class Solution {
public:

    bool dfs(string val, int idx, int target) {
        if (idx == val.size()) {
            return target == 0;
        }   

        if (target < 0) {
            return false;
        }

        long long current_part_val = 0;
        for (int end = idx; end < val.size(); end++) {
            current_part_val = current_part_val * 10 + (val[end] - '0');
            if (current_part_val > target) {
                break;
            }
            if (dfs(val, end + 1, target - current_part_val)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dfs(to_string(i*i), 0, i)) {
                ans += i*i;
            }
        }

        return ans;
    }
};
// @lc code=end

