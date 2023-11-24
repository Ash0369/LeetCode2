SELECT Max(num) as num 
FROM (SELECT Max(num) as num
FROM MyNumbers
GROUP BY(num) HAVING COUNT(num)=1 ) AS mid_query; 
