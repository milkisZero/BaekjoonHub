select i.ITEM_ID, ITEM_NAME, RARITY
from ITEM_INFO i
left join ITEM_TREE a on a.PARENT_ITEM_ID = i.ITEM_ID
where  a.ITEM_ID is null
order by i.ITEM_ID desc