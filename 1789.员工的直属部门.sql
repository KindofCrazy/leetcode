--
-- @lc app=leetcode.cn id=1789 lang=mysql
--
-- [1789] 员工的直属部门
--

-- @lc code=start
# Write your MySQL query statement below

select employee_id, department_id
from Employee 
where primary_flag = 'Y'
union
select employee_id, department_id
from Employee
group by employee_id
having count(*) = 1
-- @lc code=end

