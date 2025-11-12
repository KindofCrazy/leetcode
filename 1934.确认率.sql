--
-- @lc app=leetcode.cn id=1934 lang=mysql
--
-- [1934] 确认率
--

-- @lc code=start
# Write your MySQL query statement below

select 
    s.user_id, 
    ifnull(round(sum(c.action = 'confirmed') / count(*), 2), 0.00) as confirmation_rate
from Signups s left join Confirmations c on s.user_id = c.user_id
group by s.user_id
-- @lc code=end

