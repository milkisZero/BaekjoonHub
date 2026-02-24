select count(*) as USERS
from USER_INFO 
where JOINED like "2021-%" and AGE <= 29 and AGE >= 20