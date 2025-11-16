--
-- @lc app=leetcode.cn id=1327 lang=mysql
--
-- [1327] 列出指定时间段内所有的下单产品
--

-- @lc code=start
# Write your MySQL query statement below

select p.product_name, sum(o.unit) as unit
from Products p join Orders o on p.product_id = o.product_id
where year(o.order_date) = 2020 and month(o.order_date) = 2
group by p.product_id
having sum(o.unit) >= 100
-- @lc code=end

