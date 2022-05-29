select jno
from j
where not exists (
  select *
  from p
  where pno in (
    select pno
    from spj
    where sno = 'S1'
  ) and not exists (
    select *
    from spj
    where spj.jno = j.jno
      and spj.pno = p.pno
      and sno = 'S1'
  )
)