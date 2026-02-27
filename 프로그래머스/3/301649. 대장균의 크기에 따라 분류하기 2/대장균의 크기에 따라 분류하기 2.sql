select a.ID,	
    case when b.pr < 0.25 then "CRITICAL"
    when b.pr < 0.5 then "HIGH"
    when b.pr < 0.75 then "MEDIUM"
    else "LOW"
    end as COLONY_NAME
from ECOLI_DATA a
join (
    select ID, percent_rank() over (order by SIZE_OF_COLONY desc) as pr
    from ECOLI_DATA
) b on a.ID = b.ID
order by a.ID