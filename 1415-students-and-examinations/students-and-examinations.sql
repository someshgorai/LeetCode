# Write your MySQL query statement below
select temp.student_id, temp.student_name, temp.subject_name, count(e.student_id) as attended_exams
from 
(select st.student_id, st.student_name, sb.subject_name 
from students as st cross join subjects as sb) as temp
left join
examinations as e
on temp.student_id = e.student_id and temp.subject_name = e.subject_name
group by temp.student_id, temp.student_name, temp.subject_name
order by temp.student_id, temp.subject_name;
