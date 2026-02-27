select a.USER_ID,	a.NICKNAME, concat(CITY, " ",STREET_ADDRESS1, " ",STREET_ADDRESS2) as 전체주소, 
concat(substr(TLNO , 1, 3) , "-", substr(TLNO , 4, 4), "-", substr(TLNO , 8, 4)) as 전화번호
from USED_GOODS_USER a
join (
    select WRITER_ID, count(*) as cnt
    from USED_GOODS_BOARD 
    group by WRITER_ID
) b on a.USER_ID = b.WRITER_ID
where b.cnt >= 3
order by a.USER_ID desc