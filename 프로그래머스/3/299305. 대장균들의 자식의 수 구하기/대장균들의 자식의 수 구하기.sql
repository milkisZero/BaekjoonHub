select a.ID, ifnull(b.cnt, 0) as CHILD_COUNT
from ECOLI_DATA a
left join (
    select PARENT_ID, count(*) as cnt
    from ECOLI_DATA
    group by PARENT_ID
)b on a.ID = b.PARENT_ID
order by a.ID