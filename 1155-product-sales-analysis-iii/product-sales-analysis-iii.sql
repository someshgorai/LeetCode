# Write your MySQL query statement below
select s.product_id, s.year as first_year, s.quantity, s.price 
from sales as s
inner join
(select product_id, min(year) as first_year
from sales
group by product_id) as temp
on s.product_id = temp.product_id and s.year = temp.first_year;