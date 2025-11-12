--
-- @lc app=leetcode.cn id=1378 lang=mysql
--
-- [1378] 使用唯一标识码替换员工ID
--

-- @lc code=start
# Write your MySQL query statement below

select euni.unique_id, e.name from Employees e left join EmployeeUNI euni on e.id = euni.id;
-- @lc code=end

