# Write your MySQL query statement below
select m.employee_id, m.name, count(e.employee_id) as reports_count, round(avg(e.age), 0) as average_age 
from employees as e
inner join
employees as m
on e.reports_to = m.employee_id
group by m.employee_id
order by m.employee_id;