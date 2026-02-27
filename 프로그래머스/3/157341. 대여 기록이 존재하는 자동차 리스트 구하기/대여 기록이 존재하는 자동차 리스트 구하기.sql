select distinct a.CAR_ID
from CAR_RENTAL_COMPANY_CAR a
join (
    select CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
    where month(START_DATE) = 10
) b on a.CAR_ID=b.CAR_ID
where CAR_TYPE = "세단"
order by CAR_ID desc