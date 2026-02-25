select year(SALES_DATE) as YEAR, month(SALES_DATE) as MONTH, GENDER, count(DISTINCT a.USER_ID) as USERS
from ONLINE_SALE a
join USER_INFO b on a.USER_ID = b.USER_ID 
where GENDER = 0 or GENDER = 1
group by YEAR, MONTH, GENDER
order by YEAR asc, MONTH asc, GENDER asc