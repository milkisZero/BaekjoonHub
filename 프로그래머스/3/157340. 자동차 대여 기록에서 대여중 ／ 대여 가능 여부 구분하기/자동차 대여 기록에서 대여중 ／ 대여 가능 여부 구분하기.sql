select c.CAR_ID,
       case
           when exists (
               select 1
               from CAR_RENTAL_COMPANY_RENTAL_HISTORY h
               where h.CAR_ID = c.CAR_ID
                 and h.START_DATE <= '2022-10-16'
                 and h.END_DATE >= '2022-10-16'
           ) then '대여중'
           else '대여 가능'
       end as AVAILABILITY
from (
    select distinct CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
) c
order by c.CAR_ID desc;