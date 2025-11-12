--
-- @lc app=leetcode.cn id=197 lang=mysql
--
-- [197] 上升的温度
--

-- @lc code=start
# Write your MySQL query statement below

SELECT w1.id 
FROM Weather w1, Weather w2
WHERE date_add(w2.recordDate, INTERVAL 1 DAY)=w1.recordDate and w1.temperature > w2.temperature
-- @lc code=end

