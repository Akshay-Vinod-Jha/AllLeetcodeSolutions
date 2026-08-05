# Write your MySQL query statement below

select ls.customer_id  as customer_id , count(*) as count_no_trans
from
Visits as ls
left join
(select distinct visit_id from Transactions) as rs
on ls.visit_id = rs.visit_id
where rs.visit_id is null

group by customer_id