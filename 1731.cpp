# Write your MySQL query statement below
SELECT e2.employee_id,e2.name,COUNT(e2.name) as reports_count,ROUND(SUM(e1.age)/COUNT(e2.name)) as average_age
FROM Employees e1 JOIN Employees e2 ON e1.reports_to=e2.employee_id
GROUP BY(e2.employee_id)
Order by e2.employee_id
