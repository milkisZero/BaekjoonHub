select a.APNT_NO, b.PT_NAME,	a.PT_NO, 	c.MCDP_CD,	c.DR_NAME,	a.APNT_YMD 
from APPOINTMENT a 
join PATIENT b on a.PT_NO = b.PT_NO
join DOCTOR  c on a.MDDR_ID = c.DR_ID
where  a.APNT_CNCL_YMD is null and c.MCDP_CD = "CS"
  AND a.APNT_YMD >= '2022-04-13'
  AND a.APNT_YMD <  '2022-04-14'
order by a.APNT_YMD