-- Write your PostgreSQL query statement below
SELECT t.id 
FROM Weather AS y
CROSS JOIN
Weather AS t
WHERE (t.recordDate - y.recordDate) = 1 AND
(t.temperature > y.temperature);