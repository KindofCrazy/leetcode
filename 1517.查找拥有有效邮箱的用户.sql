--
-- @lc app=leetcode.cn id=1517 lang=mysql
--
-- [1517] 查找拥有有效邮箱的用户
--

-- @lc code=start
# Write your MySQL query statement below

select * 
from Users
where mail regexp '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$' COLLATE utf8mb4_0900_as_cs
-- @lc code=end

