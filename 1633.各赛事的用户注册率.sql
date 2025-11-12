--
-- @lc app=leetcode.cn id=1633 lang=mysql
--
-- [1633] 各赛事的用户注册率
--

-- @lc code=start
# Write your MySQL query statement below

select contest_id, round(count(*) * 100 / (select count(*) from users), 2) as percentage
from Register r 
group by contest_id
order by percentage desc, contest_id asc
-- @lc code=end

