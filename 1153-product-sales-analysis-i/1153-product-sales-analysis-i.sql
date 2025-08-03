# Write your MySQL query statement below
select table1.product_name as product_name , table2.year as year ,
table2.price 
from
Sales as table2
inner join 
Product table1
on table1.product_id = table2.product_id