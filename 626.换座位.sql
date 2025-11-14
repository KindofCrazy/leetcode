--
-- @lc app=leetcode.cn id=626 lang=mysql
--
-- [626] 换座位
--

-- @lc code=start
# Write your MySQL query statement below

select s1.id, ifnull(s2.student, s1.student) as student
from Seat s1 left join Seat s2 on (s1.id+1)^1 - 1 = s2.id
order by s1.id
