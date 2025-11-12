--
-- @lc app=leetcode.cn id=1174 lang=mysql
--
-- [1174] 即时食物配送 II
--

-- @lc code=start
# Write your MySQL query statement below

select round(100 * sum(order_date = customer_pref_delivery_date)/ count(*) , 2) as immediate_percentage
from Delivery
where (customer_id, order_date) in (
    select customer_id, min(order_date)
    from Delivery
    group by customer_id
)
-- @lc code=end

