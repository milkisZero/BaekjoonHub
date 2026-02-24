select ITEM_ID,	ITEM_NAME,	RARITY
from ITEM_INFO
where ITEM_ID in (
    select b.ITEM_ID
    from ITEM_INFO a, ITEM_TREE b
    where b.PARENT_ITEM_ID = a.ITEM_ID and a.RARITY = "RARE"
)
order by ITEM_ID desc