# Write your MySQL query statement below
select e.employee_id, e.department_id
from employee as e
left join
(select employee_id, count(department_id) as cntDept, primary_flag
from employee
group by employee_id) as temp
on e.employee_id = temp.employee_id
where (temp.cntDept = 1) or (temp.cntDept >= 2 and e.primary_flag = 'Y'); 