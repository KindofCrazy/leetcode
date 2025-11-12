--
-- @lc app=leetcode.cn id=2356 lang=mysql
--
-- [2356] 每位教师所教授的科目种类的数量
--

-- @lc code=start
# Write your MySQL query statement below

select teacher_id, count(distinct subject_id) as cnt
from Teacher
group by teacher_id
-- @lc code=end

