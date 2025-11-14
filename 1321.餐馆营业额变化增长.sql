--
-- @lc app=leetcode.cn id=1321 lang=mysql
--
-- [1321] 餐馆营业额变化增长
--

-- @lc code=start
# Write your MySQL query statement below

select c1.visited_on, sum(c2.amount) as amount, round(sum(c2.amount) / 7, 2) as average_amount
from (select distinct visited_on from Customer) c1
join Customer c2 on c2.visited_on between date_sub(c1.visited_on, interval 6 day) and c1.visited_on
group by c1.visited_on
having count(distinct c2.visited_on) = 7
order by c1.visited_on
-- @lc code=end

