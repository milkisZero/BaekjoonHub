select month(a.START_DATE) as MONTH,	a.CAR_ID,	count(*) as RECORDS
from (
    select *, count(*) over(partition by CAR_ID) as cnt
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where START_DATE between '2022-08-01' and'2022-11-01'
) a
where a.cnt >= 5
group by MONTH, a.CAR_ID
order by MONTH asc, a.CAR_ID desc