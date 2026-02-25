with recursive hours as (
    select 0 as HOUR
    union all
    select HOUR + 1
    from hours
    where HOUR < 23
)
select h.HOUR, count(hour(a.DATETIME)) asCOUNT
from hours h
left join ANIMAL_OUTS a on hour(a.DATETIME) = h.HOUR
group by h.HOUR
order by h.HOUR;