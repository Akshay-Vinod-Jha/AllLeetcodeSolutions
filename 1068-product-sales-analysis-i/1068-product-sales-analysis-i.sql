# Write your MySQL query statement below
select right_side.product_name  as product_name , left_side.year  as year , left_side.price as price 
from Sales as left_side 
left join
Product as right_side
on left_side.product_id = right_side.product_id