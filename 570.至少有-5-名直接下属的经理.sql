--
-- @lc app=leetcode.cn id=570 lang=mysql
--
-- [570] 至少有5名直接下属的经理
--

-- @lc code=start
# Write your MySQL query statement below

-- select e.name
-- from (
--     select e2.name, count(*) as cnt
--     from Employee e1
--     join Employee e2 on e1.managerID = e2.id
--     group by e2.id
-- ) e 
-- where e.cnt >= 5

select e2.name 
from Employee e1 join Employee e2 on e1.managerID = e2.id
group by e2.id
having count(*) >= 5
-- @lc code=end

