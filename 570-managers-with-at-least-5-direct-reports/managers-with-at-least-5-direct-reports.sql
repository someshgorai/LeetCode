# Write your MySQL query statement below
select e.name
from employee as e
inner join 
(select managerId
from employee 
group by managerId
having count(managerId) >= 5) as temp
on e.id = temp.managerId;