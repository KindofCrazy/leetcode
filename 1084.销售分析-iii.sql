--
-- @lc app=leetcode.cn id=1084 lang=mysql
--
-- [1084] 销售分析 III
--

-- @lc code=start
# Write your MySQL query statement below

select p.product_id , p.product_name
from Product p join Sales s on p.product_id = s.product_id
group by p.product_id
having min(s.sale_date) >= '2019-01-01' and max(s.sale_date) <= '2019-03-31'
-- @lc code=end

