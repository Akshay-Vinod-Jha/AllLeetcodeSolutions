select id 
from (
    select id,
       recordDate,
       temperature,
       LAG(temperature, 1, NULL) OVER (ORDER BY recordDate) AS ptemperature,
       DATEDIFF(recordDate,LAG(recordDate, 1, SUBDATE(recordDate, INTERVAL 2 DAY)) OVER (ORDER BY recordDate)) as datediff
    FROM (
    select * from Weather order by recordDate
    ) as table1
) as table2
where table2.datediff = 1 and table2.temperature > table2.ptemperature 