# Write your MySQL query statement below
select e.name
from employee as e
inner join 
(select managerId, count(managerId) as freq
from employee 
group by managerId) as temp
on e.id = temp.managerId
where temp.freq >= 5;