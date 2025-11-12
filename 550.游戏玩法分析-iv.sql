--
-- @lc app=leetcode.cn id=550 lang=mysql
--
-- [550] 游戏玩法分析 IV
--

-- @lc code=start
# Write your MySQL query statement below

select round(
    count(a3.player_id) / (select count(distinct a4.player_id) from Activity a4)
    , 2) as fraction
from (
    select a2.player_id
    from Activity a2
    where (a2.player_id, a2.event_date) in (
        select a1.player_id, date_add(min(a1.event_date), interval 1 day)
        from Activity a1
        group by a1.player_id
    ) 
) a3
-- @lc code=end

