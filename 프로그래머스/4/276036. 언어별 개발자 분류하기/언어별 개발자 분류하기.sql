SELECT GRADE, ID, EMAIL
FROM (
    SELECT
        CASE
            WHEN EXISTS (
                SELECT 1
                FROM SKILLCODES s
                WHERE s.NAME = 'Python'
                  AND (a.SKILL_CODE & s.CODE) != 0
            )
             AND EXISTS (
                SELECT 1
                FROM SKILLCODES s
                WHERE s.CATEGORY = 'Front End'
                  AND (a.SKILL_CODE & s.CODE) != 0
            ) THEN 'A'
            WHEN EXISTS (
                SELECT 1
                FROM SKILLCODES s
                WHERE s.NAME = 'C#'
                  AND (a.SKILL_CODE & s.CODE) != 0
            ) THEN 'B'
            WHEN EXISTS (
                SELECT 1
                FROM SKILLCODES s
                WHERE s.CATEGORY = 'Front End'
                  AND (a.SKILL_CODE & s.CODE) != 0
            ) THEN 'C'
            ELSE 'D'
        END AS GRADE,
        a.ID,
        a.EMAIL
    FROM DEVELOPERS a
) x
WHERE x.GRADE <> 'D'
ORDER BY x.GRADE, x.ID;