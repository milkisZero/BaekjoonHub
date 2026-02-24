select a.REST_ID, a.REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, score
from REST_INFO as a
JOIN (
    SELECT rest_id, ROUND(AVG(review_score),2) AS score 
    FROM rest_review 
    GROUP BY rest_id) b ON a.rest_id = b.rest_id
where ADDRESS like "서울%" 
order by SCORE desc, FAVORITES desc