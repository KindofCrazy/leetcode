--
-- @lc app=leetcode.cn id=185 lang=mysql
--
-- [185] 部门工资前三高的所有员工
--

-- @lc code=start
# Write your MySQL query statement below

select d.name as department, e.name as Employee, e.salary as Salary
from Employee e 
join Department d on e.departmentId = d.id
where (
    select count(distinct e2.salary)
    from Employee e2
    where e.departmentId = e2.departmentId and e2.salary > e.salary
) <= 2
-- @lc code=end

