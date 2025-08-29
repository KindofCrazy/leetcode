/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    int binarySearch(vector<char>& letters, char target) {
        int n = letters.size(), left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (letters[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        int pos = binarySearch(letters, target+1);
        if (pos == letters.size()) {
            return letters[0];
        } else {
            return letters[pos];
        }
    }
};
// @lc code=end

