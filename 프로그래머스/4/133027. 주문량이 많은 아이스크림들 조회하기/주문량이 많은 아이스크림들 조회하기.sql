select a.FLAVOR
from FIRST_HALF a
join (
    select FLAVOR, sum(TOTAL_ORDER) as s
    from JULY 
    group by FLAVOR
) b on a.FLAVOR = b.FLAVOR
group by a.FLAVOR
order by (sum(a.TOTAL_ORDER) + sum(b.s)) desc
limit 3