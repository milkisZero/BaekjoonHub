select a.ID, a.GENOTYPE, b.GENOTYPE as PARENT_GENOTYPE
from ECOLI_DATA a
join (
    select ID, GENOTYPE
    from ECOLI_DATA
) b on a.PARENT_ID = b.ID
where (a.GENOTYPE & b.GENOTYPE) != 0 and  (a.GENOTYPE | b.GENOTYPE) = a.GENOTYPE 
order by a.ID