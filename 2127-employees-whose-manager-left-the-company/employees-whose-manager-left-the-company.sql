# Write your MySQL query statement below
select e.employee_id
from employees as e
left join
employees as m
on m.employee_id = e.manager_id
where m.employee_id is null and e.manager_id is not null
and e.salary < 30000
order by e.employee_id;