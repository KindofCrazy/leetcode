--
-- @lc app=leetcode.cn id=1661 lang=mysql
--
-- [1661] 每台机器的进程平均运行时间
--

-- @lc code=start
# Write your MySQL query statement below

SELECT a1.machine_id, ROUND(AVG(a2.timestamp - a1.timestamp), 3) AS processing_time
FROM Activity a1 join Activity a2 ON a1.machine_id = a2.machine_id and a1.process_id = a2.process_id
WHERE a1.activity_type = 'start' and a2.activity_type = 'end'
GROUP BY a1.machine_id;
-- @lc code=end

