--
-- @lc app=leetcode.cn id=1204 lang=mysql
--
-- [1204] 最后一个能进入巴士的人
--

-- @lc code=start
# Write your MySQL query statement below

select q1.person_name
from Queue q1 join Queue q2 on q1.turn >= q2.turn
group by q1.person_id
having sum(q2.weight) <= 1000
order by q1.turn desc
limit 1
-- @lc code=end

