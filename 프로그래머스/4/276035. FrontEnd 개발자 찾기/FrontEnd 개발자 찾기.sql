select DISTINCT a.ID,	EMAIL,	FIRST_NAME,	LAST_NAME
from DEVELOPERS a
join (
    select CODE
    from SKILLCODES 
    where CATEGORY = "Front End"
) b on (a.SKILL_CODE & b.CODE) != 0
order by a.ID