/*
 * @lc app=leetcode.cn id=2336 lang=cpp
 *
 * [2336] 无限集中的最小数字
 */

// @lc code=start
class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> valid;

    SmallestInfiniteSet() {
        valid.resize(1001, true);
        for(int i = 1; i <= 1000; i++) {
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int x = pq.top();
        pq.pop();
        valid[x] = false;
        return x;
    }
    
    void addBack(int num) {
        if (!valid[num]) {
            valid[num] = true;
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end

