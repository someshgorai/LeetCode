# Write your MySQL query statement below
select person_name
from 
(select person_name,
sum(weight) over(order by turn) as cumm
from queue) as temp
where temp.cumm <= 1000 
order by temp.cumm desc
limit 1;
