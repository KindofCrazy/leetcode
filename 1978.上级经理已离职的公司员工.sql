--
-- @lc app=leetcode.cn id=1978 lang=mysql
--
-- [1978] 上级经理已离职的公司员工
--

-- @lc code=start
# Write your MySQL query statement below

select employee_id
from Employees
where salary < 30000 and manager_id not in (
    select employee_id
    from Employees
)
order by employee_id
-- @lc code=end

