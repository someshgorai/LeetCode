# Write your MySQL query statement below
SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary 
FROM employee AS e INNER JOIN department as d ON e.departmentId = d.id
WHERE (e.departmentId, e.salary) IN 
(SELECT departmentId, MAX(salary) FROM employee GROUP BY departmentID);
