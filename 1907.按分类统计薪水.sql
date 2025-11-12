--
-- @lc app=leetcode.cn id=1907 lang=mysql
--
-- [1907] 按分类统计薪水
--

-- @lc code=start
# Write your MySQL query statement below

select "Low Salary" as category, count(*) as accounts_count
from Accounts 
where income < 20000
union
select "Average Salary" as category, count(*) 
from Accounts
where income between 20000 and 50000
union select "High Salary", count(*)
from Accounts
where income > 50000
-- @lc code=end

