select 
    month(a.START_DATE) as MONTH,
    a.CAR_ID,
    count(*) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY a
join (
    select CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where START_DATE >= '2022-08-01'
      and START_DATE < '2022-11-01'
    group by CAR_ID
    having count(*) >= 5
) b on a.CAR_ID = b.CAR_ID
where a.START_DATE >= '2022-08-01'
  and a.START_DATE < '2022-11-01'
group by month(a.START_DATE), a.CAR_ID
order by MONTH asc, a.CAR_ID desc;