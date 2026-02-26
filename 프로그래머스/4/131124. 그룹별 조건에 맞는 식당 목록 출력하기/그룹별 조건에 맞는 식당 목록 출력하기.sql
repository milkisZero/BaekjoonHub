select a.MEMBER_NAME,	c.REVIEW_TEXT,	date_format(c.REVIEW_DATE, "%Y-%m-%d") as REVIEW_DATE
from MEMBER_PROFILE a
join (
    select MEMBER_ID, count(*) as cnt
    from REST_REVIEW 
    group by MEMBER_ID 
    order by cnt desc
    limit 1
) b on a.MEMBER_ID = b.MEMBER_ID
join (
    select MEMBER_ID, REVIEW_TEXT, REVIEW_DATE
    from REST_REVIEW 
) c on a.MEMBER_ID = c.MEMBER_ID
order by REVIEW_DATE asc, c.REVIEW_TEXT asc