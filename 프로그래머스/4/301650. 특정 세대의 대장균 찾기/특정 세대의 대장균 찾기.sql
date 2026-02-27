with recursive gene as (
    select ID, PARENT_ID, 1 as k
    from ECOLI_DATA 
    where PARENT_ID is null
    
    union all
    
    select a.ID, a.PARENT_ID, k+1 as k
    from gene g
    join ECOLI_DATA a on a.PARENT_ID = g.ID
)

select ID
from gene
where k = 3