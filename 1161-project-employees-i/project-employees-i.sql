# Write your MySQL query statement below
select p.project_id, ifnull(round(avg(e.experience_years), 2), 0.00) as average_years 
from project as p
left join
employee as e
using (employee_id)
group by p.project_id;