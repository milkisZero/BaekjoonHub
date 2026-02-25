select count(*) as FISH_COUNT, max(ifnull(a.LENGTH, b.k)) as MAX_LENGTH,	FISH_TYPE 
from FISH_INFO a
left join (
    select ID, 10 as k
    from FISH_INFO
    where LENGTH is null
) b on a.ID = b.ID
group by FISH_TYPE
having avg(ifnull(a.LENGTH, b.k))  >= 33
order by FISH_TYPE asc