select i.ITEM_ID, ITEM_NAME, RARITY
from ITEM_INFO i
where not exists (
    select 1
    from  ITEM_TREE a
    where a.PARENT_ITEM_ID = i.ITEM_ID
)
order by i.ITEM_ID desc