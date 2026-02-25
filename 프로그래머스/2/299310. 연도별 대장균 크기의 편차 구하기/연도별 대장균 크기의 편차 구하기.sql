select year(e.DIFFERENTIATION_DATE) as YEAR, (j.maxi - SIZE_OF_COLONY) as YEAR_DEV,	e.ID
from ECOLI_DATA e
join (
    select year(DIFFERENTIATION_DATE) as year, max(SIZE_OF_COLONY) as maxi
    from ECOLI_DATA
    group by year(DIFFERENTIATION_DATE)
) j on year(e.DIFFERENTIATION_DATE) = j.year
order by YEAR asc, YEAR_DEV asc