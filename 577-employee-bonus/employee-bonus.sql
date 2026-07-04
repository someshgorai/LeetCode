-- Write your PostgreSQL query statement below
select name, bonus from 
(select e.name, b.bonus
from employee as e left join bonus as b 
on e.empId = b.empId)
where bonus < 1000 or bonus is null;