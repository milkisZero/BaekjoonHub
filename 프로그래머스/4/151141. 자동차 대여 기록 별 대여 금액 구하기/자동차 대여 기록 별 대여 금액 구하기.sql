select distinct HISTORY_ID, 
round((datediff(END_DATE, START_DATE)+1) *b.DAILY_FEE * (1 - 0.01 * ifnull(DISCOUNT_RATE, 0)), 0) as FEE
from CAR_RENTAL_COMPANY_RENTAL_HISTORY a
join CAR_RENTAL_COMPANY_CAR b on a.CAR_ID = b.CAR_ID
left join CAR_RENTAL_COMPANY_DISCOUNT_PLAN c on b.CAR_TYPE = c.CAR_TYPE
and c.DURATION_TYPE = 
    case when (datediff(END_DATE, START_DATE)+1 >= 90) then "90일 이상"
        when (datediff(END_DATE, START_DATE)+1 >= 30) then "30일 이상"
        when (datediff(END_DATE, START_DATE)+1 >= 7) then "7일 이상"
    end
where b.CAR_TYPE = "트럭"
order by FEE desc, HISTORY_ID desc