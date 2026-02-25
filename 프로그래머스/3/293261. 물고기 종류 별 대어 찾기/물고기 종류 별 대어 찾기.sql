select a.ID, b.FISH_NAME, c.maxi as LENGTH
from FISH_INFO a
join FISH_NAME_INFO b on a.FISH_TYPE = b.FISH_TYPE
join (
    select FISH_TYPE, max(LENGTH) as maxi
    from FISH_INFO
    where LENGTH is not null
    group by FISH_TYPE 
) c on c.maxi = a.LENGTH and c.FISH_TYPE = a.FISH_TYPE
order by ID asc