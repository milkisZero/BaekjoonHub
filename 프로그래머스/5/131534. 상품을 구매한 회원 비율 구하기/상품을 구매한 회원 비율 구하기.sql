select  year(SALES_DATE) as YEAR, month(SALES_DATE) as	MONTH, count(distinct a.USER_ID) as	PURCHASED_USERS	, round(count(distinct a.USER_ID) /  (
    select count(distinct USER_ID) as cnt
    from USER_INFO 
    where year(JOINED) = 2021
), 1) as PUCHASED_RATIO
from ONLINE_SALE a
join USER_INFO b on a.USER_ID = b.USER_ID
where year(JOINED) = 2021
group by year(SALES_DATE) , month(SALES_DATE)
order by YEAR, MONTH