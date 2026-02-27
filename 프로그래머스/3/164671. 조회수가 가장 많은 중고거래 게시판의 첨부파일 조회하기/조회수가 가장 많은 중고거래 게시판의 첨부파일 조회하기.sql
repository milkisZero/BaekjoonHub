select concat("/home/grep/src/",a.BOARD_ID,"/",FILE_ID,FILE_NAME,FILE_EXT ) as FILE_PATH
from USED_GOODS_FILE a
join (
    select BOARD_ID, max(VIEWS) as maxi
    from USED_GOODS_BOARD 
    group by BOARD_ID
    order by maxi desc
    limit 1
) b on a.BOARD_ID = b.BOARD_ID
order by FILE_ID desc