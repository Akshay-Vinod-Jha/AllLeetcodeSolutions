# Write your MySQL query statement below
with table1 as (
    select * ,
            ROW_NUMBER() OVER(PARTITION BY player_id ORDER BY event_date) as isrank
    from Activity 
),
table2 as (
    select * from table1 where isrank=1
),
table3 as (
    select * from table1 where isrank=2
),
table4 as (
    select table3.player_id , datediff(table3.event_date,table2.event_date) as diffindate from 
    table3 
    left join 
    table2
    on table3.player_id = table2.player_id
),
table5 as (
    select * from table4 where diffindate = 1
)

select round((select count(*) from table5)/(select count(*) from table2),2) as fraction 