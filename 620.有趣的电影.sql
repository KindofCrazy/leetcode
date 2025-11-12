--
-- @lc app=leetcode.cn id=620 lang=mysql
--
-- [620] 有趣的电影
--

-- @lc code=start
# Write your MySQL query statement below

select *
from cinema c
where c.description != 'boring' and c.id % 2 = 1
order by c.rating desc
-- @lc code=end

