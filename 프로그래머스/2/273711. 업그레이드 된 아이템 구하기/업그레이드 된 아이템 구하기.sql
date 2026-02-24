select b.ITEM_ID,	b.ITEM_NAME,	b.RARITY
from ITEM_TREE t
join ITEM_INFO a on a.ITEM_ID = t.PARENT_ITEM_ID
join ITEM_INFO b on b.ITEM_ID = t.ITEM_ID
where a.RARITY = "RARE"
order by b.ITEM_ID desc