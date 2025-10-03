/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> pqMax;
    priority_queue<int, vector<int>, greater<int>> pqMin;


    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (pqMax.empty() || num <= pqMax.top()) {
            pqMax.push(num);
            if (pqMax.size() > pqMin.size() + 1) {
                pqMin.push(pqMax.top());
                pqMax.pop();
            }
        } else {
            pqMin.push(num);
            if (pqMin.size() > pqMax.size()) {
                pqMax.push(pqMin.top());
                pqMin.pop();
            }
        }
    }
    
    double findMedian() {
        if (pqMax.size() > pqMin.size()) {
            return pqMax.top();
        }

        return (pqMax.top() + pqMin.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

