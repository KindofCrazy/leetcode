--
-- @lc app=leetcode.cn id=1045 lang=mysql
--
-- [1045] 买下所有产品的客户
--

-- @lc code=start
# Write your MySQL query statement below

select c.customer_id
from Customer c join Product p on c.product_key = p.product_key
group by c.customer_id
having count(distinct p.product_key) = (select count(*) from Product)
-- @lc code=end

