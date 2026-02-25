select distinct a.CAR_ID, ifnull(b.k, "대여 가능") as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY a
left join (
    select CAR_ID, "대여중" as k
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where START_DATE <= '2022-10-16' and END_DATE >= '2022-10-16'
    group by CAR_ID
) b on a.CAR_ID = b.CAR_ID
order by a.CAR_ID desc