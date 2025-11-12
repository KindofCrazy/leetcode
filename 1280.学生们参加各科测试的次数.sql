--
-- @lc app=leetcode.cn id=1280 lang=mysql
--
-- [1280] 学生们参加各科测试的次数
--

-- @lc code=start
# Write your MySQL query statement below

select s.student_id, s.student_name, sub.subject_name, ifnull(e.cnt, 0) as attended_exams
from Students s 
join Subjects sub
left join (
    select student_id, subject_name, count(*) as cnt
    from Examinations
    group by student_id, subject_name
) e on s.student_id = e.student_id and sub.subject_name = e.subject_name
order by s.student_id, sub.subject_name
-- @lc code=end

