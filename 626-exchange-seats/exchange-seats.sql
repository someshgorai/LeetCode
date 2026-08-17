# Write your MySQL query statement below
select 
    case
        when id & 1 = 1 and id + 1 in (select id from seat) then id + 1
        when id & 1 = 0 then id - 1
        else id
    end
as id, student
from seat
order by id;