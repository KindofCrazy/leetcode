--
-- @lc app=leetcode.cn id=1211 lang=mysql
--
-- [1211] 查询结果的质量和占比
--

-- @lc code=start
# Write your MySQL query statement below

select query_name, 
        round(avg(rating / position), 2) as quality, 
        round(sum(rating < 3) * 100/ count(*), 2) as poor_query_percentage
from Queries q
group by query_name
-- @lc code=end

