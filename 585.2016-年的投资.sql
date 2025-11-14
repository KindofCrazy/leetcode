--
-- @lc app=leetcode.cn id=585 lang=mysql
--
-- [585] 2016年的投资
--

-- @lc code=start
# Write your MySQL query statement below

select round(sum(i.tiv_2016), 2) as tiv_2016
from Insurance i 
where i.tiv_2015 in (
    select tiv_2015
    from Insurance
    where i.pid != pid
) and (i.lat, i.lon) not in (
    select lat, lon
    from Insurance
    where i.pid != pid
)
-- @lc code=end

