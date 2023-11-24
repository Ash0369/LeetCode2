SELECT name,CASE WHEN SUM(distance) IS NULL THEN 0 ELSE SUM(distance) END as travelled_distance
FROM Users left join Rides ON Users.id=Rides.user_id
GROUP BY(Users.id)
ORDER BY (travelled_distance) DESC,name
