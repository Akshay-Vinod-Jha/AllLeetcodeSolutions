select 
lt.machine_id,
round(sum(round(rt.timestamp-lt.timestamp,3))/ count(*),3) as processing_time 
from Activity  as lt
left join Activity as rt
on lt.machine_id = rt.machine_id and lt.process_id = rt.process_id 
where lt.activity_type = 'start' and rt.activity_type = 'end'

group by lt.machine_id 