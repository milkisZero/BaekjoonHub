with recursive gene as (
    select ID, PARENT_ID, 1 as k
    from ECOLI_DATA 
    where PARENT_ID is null
    
    union all
    
    select b.ID, b.PARENT_ID, k+1 as k
    from gene a
    join ECOLI_DATA b on a.ID = b.PARENT_ID
)

select count(*) as COUNT, g.k as GENERATION
from ECOLI_DATA a 
join gene g on a.ID = g.ID
where not exists (
    select 1
    from ECOLI_DATA e
    where e.PARENT_ID = a.ID
)
group by GENERATION
order by GENERATION