select a.CATEGORY,  PRICE as MAX_PRICE, PRODUCT_NAME
from FOOD_PRODUCT a
join (
    select CATEGORY, max(PRICE) as k
    from FOOD_PRODUCT
    group by CATEGORY
) b on a.PRICE = b.k and a.CATEGORY = b.CATEGORY
where a.CATEGORY = "과자" or a.CATEGORY = "국" or a.CATEGORY = "김치" or a.CATEGORY = "식용유" 
order by MAX_PRICE desc