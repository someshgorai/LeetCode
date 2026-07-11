# Write your MySQL query statement below
select person_name
from queue as q
join
(select person_id,
sum(weight) over(order by turn) as cumm
from queue) as temp
on q.person_id = temp.person_id
where temp.cumm <= 1000 
order by temp.cumm desc
limit 1;
