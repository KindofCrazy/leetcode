--
-- @lc app=leetcode.cn id=610 lang=mysql
--
-- [610] 判断三角形
--

-- @lc code=start
# Write your MySQL query statement below

select *, if(x+y>z and x+z>y and y+z>x, "Yes", "No") as triangle
from Triangle
-- @lc code=end

