select CATEGORY, sum(b.s) as TOTAL_SALES
from BOOK a
join (
    select BOOK_ID, sum(SALES) as s
    from BOOK_SALES
    where year(SALES_DATE) = 2022 and month(SALES_DATE) = 1
    group by BOOK_ID
) b on a.BOOK_ID = b.BOOK_ID
group by CATEGORY
order by CATEGORY asc