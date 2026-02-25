select 
    a.AUTHOR_ID,
    b.AUTHOR_NAME,
    a.CATEGORY,
    sum(a.PRICE * c.k) as TOTAL_SALES
from BOOK a
join AUTHOR b on a.AUTHOR_ID = b.AUTHOR_ID
join (
    select BOOK_ID, sum(SALES) as k
    from BOOK_SALES
    where SALES_DATE like '2022-01-%'
    group by BOOK_ID
) c on c.BOOK_ID = a.BOOK_ID
group by a.AUTHOR_ID, b.AUTHOR_NAME, a.CATEGORY
order by a.AUTHOR_ID asc, a.CATEGORY desc;