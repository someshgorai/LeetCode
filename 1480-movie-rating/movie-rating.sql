# Write your MySQL query statement below

(
    select u.name as results
    from movierating as m
    inner join 
    users as u
    on u.user_id = m.user_id
    group by u.user_id
    order by count(m.movie_id) desc, u.name
    limit 1
)
union all
(   select m.title as results
    from movierating as r
    inner join 
    movies as m
    on r.movie_id = m.movie_id
    where r.created_at >= '2020-02-01'
        and r.created_at < '2020-03-01'
    group by r.movie_id
    order by avg(r.rating)desc, m.title asc
    limit 1
)

