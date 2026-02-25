select x.EMP_NO,	x.EMP_NAME,	 x.GRADE
, case 
    when (
        GRADE = "S"
    ) then SAL * 0.2
    when (
        GRADE = "A"
    ) then SAL * 0.15
    when (
        GRADE = "B"
    ) then SAL * 0.1
    else 0
    end as BONUS
from (
    select case 
    when (
        avg(b.SCORE) >= 96
    ) then "S"
    when (
         avg(b.SCORE) >= 90
    ) then "A"
       when (
         avg(b.SCORE) >= 80
    ) then "B"
    else "C"
    end as GRADE, a.EMP_NO,	a.EMP_NAME, a.SAL
    from HR_EMPLOYEES a 
    join (
        select EMP_NO, SCORE
        from HR_GRADE 
    ) b on a.EMP_NO = b.EMP_NO
    group by a.EMP_NO, EMP_NAME
) x
order by x.EMP_NO