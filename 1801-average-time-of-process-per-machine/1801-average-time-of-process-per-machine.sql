# Write your MySQL query statement below
select machine_id , round(avg(diff),3) as processing_time from (
    select table1.machine_id , table1.process_id , round(table2.timestamp - table1.timestamp,3) as diff
from 
    (select * from Activity where activity_type = "start") as table1
    inner join
    (select * from Activity where activity_type = "end") as table2
on table1.machine_id=table2.machine_id and table1.process_id = table2.process_id
) as imptable group by machine_id