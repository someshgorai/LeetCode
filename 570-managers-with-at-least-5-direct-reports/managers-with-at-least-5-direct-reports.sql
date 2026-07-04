# Write your MySQL query statement below
select e.name
from employee as e
inner join 
employee as m
on e.id = m.managerId
group by e.id
having count(m.managerId) >= 5;