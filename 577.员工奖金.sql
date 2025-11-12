--
-- @lc app=leetcode.cn id=577 lang=mysql
--
-- [577] 员工奖金
--

-- @lc code=start
# Write your MySQL query statement below

SELECT e.name, b.bonus
FROM Employee e LEFT JOIN Bonus b ON e.empId = b.empId
WHERE b.bonus is NULL OR b.bonus < 1000;
-- @lc code=end

