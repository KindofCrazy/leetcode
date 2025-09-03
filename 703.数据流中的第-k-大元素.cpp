/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int rank;

    KthLargest(int k, vector<int>& nums) {
        rank = k;
        for (int n: nums) {
            if (pq.size() < rank) pq.push(n);
            else if (n > pq.top()) {
                pq.pop();
                pq.push(n);
            }
        }
    }
    
    int add(int val) {
        if (pq.size() < rank) pq.push(val);
        else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

