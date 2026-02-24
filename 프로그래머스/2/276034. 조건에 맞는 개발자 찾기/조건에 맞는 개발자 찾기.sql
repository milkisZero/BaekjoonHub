select distinct ID,	EMAIL,	FIRST_NAME,	LAST_NAME
from DEVELOPERS d
join SKILLCODES s on (d.SKILL_CODE & s.CODE) > 0
where s.NAME = 'C#' or s.NAME = 'Python'
order by ID asc