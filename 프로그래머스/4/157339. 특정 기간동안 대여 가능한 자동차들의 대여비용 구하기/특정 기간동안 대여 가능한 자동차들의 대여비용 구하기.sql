select a.CAR_ID, 	a.CAR_TYPE,  round ((a.DAILY_FEE * 30 - a.DAILY_FEE * 30 * ifnull(c.DISCOUNT_RATE, 0)/ 100), 0 )as FEE
from CAR_RENTAL_COMPANY_CAR a
left join (
    select CAR_TYPE, DISCOUNT_RATE
    from CAR_RENTAL_COMPANY_DISCOUNT_PLAN 
    where DURATION_TYPE = "30일 이상"
) c on a.CAR_TYPE = c.CAR_TYPE
where NOT EXISTS (
      SELECT 1
      FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY h
      WHERE h.CAR_ID = a.CAR_ID
        AND h.START_DATE <= '2022-11-30'
        AND h.END_DATE   >= '2022-11-01'
  ) and a.CAR_TYPE IN ('세단', 'SUV') 
  and (a.DAILY_FEE * 30 - a.DAILY_FEE * 30 * ifnull(c.DISCOUNT_RATE, 0) / 100) >= 500000
  and (a.DAILY_FEE * 30 - a.DAILY_FEE * 30 * ifnull(c.DISCOUNT_RATE, 0) / 100) < 2000000
order by FEE desc, a.CAR_TYPE asc, a.CAR_ID desc