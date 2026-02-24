select c.ITEM_ID, c.ITEM_NAME
from ITEM_TREE a
join ITEM_INFO c on c.ITEM_ID = a.ITEM_ID 
where a.PARENT_ITEM_ID is null
order by c.ITEM_ID asc