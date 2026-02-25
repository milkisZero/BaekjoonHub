select a.USER_ID, a.NICKNAME, b.s as TOTAL_SALES
from USED_GOODS_USER  a
join (
    select WRITER_ID, sum(PRICE) as s
    from USED_GOODS_BOARD  
    where STATUS = "DONE"
    group by WRITER_ID
) b on a.USER_ID = b.WRITER_ID
where b.s >= 700000
order by TOTAL_SALES asc
