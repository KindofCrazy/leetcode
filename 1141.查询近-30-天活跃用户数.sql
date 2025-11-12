--
-- @lc app=leetcode.cn id=1141 lang=mysql
--
-- [1141] 查询近30天活跃用户数
--

-- @lc code=start
# Write your MySQL query statement below

select activity_date as day, count(distinct user_id) as active_users
from Activity
where activity_date BETWEEN date_sub('2019-07-27', interval 29 day) and '2019-07-27'
group by activity_date
-- @lc code=end

