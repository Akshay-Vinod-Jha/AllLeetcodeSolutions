# Write your MySQL query statement below
with table1 as (
    select tiv_2015 , count(*) as iscount from Insurance group by tiv_2015
),
table3 as (
    select * from (select lat , lon , count(*) as isrepeated from Insurance group by lat,lon ) as dummy1 where isrepeated > 1
),
table4 as (
    select pid from Insurance where exists (select 1 from table3 where table3.lat= Insurance.lat and table3.lon=Insurance.lon )
),
table2 as (
    select round(sum(tiv_2016),2) as tiv_2016 from 
    Insurance
    inner join
    table1
    on Insurance.tiv_2015 = table1.tiv_2015
    where iscount >=2 and pid not in (select pid from table4)
)

select * from table2