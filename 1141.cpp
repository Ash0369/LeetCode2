# Write your MySQL query statement below
SELECT activity_date as day,COUNT(user_id) as active_users
FROM(
SELECT activity_date,user_id
FROM Activity
WHERE activity_date>="2019-06-28" and activity_date<="2019-07-27" 
GROUP BY activity_date,user_id
) as gf
GROUP BY(activity_date)
