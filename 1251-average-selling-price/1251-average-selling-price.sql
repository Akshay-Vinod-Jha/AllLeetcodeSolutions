select first.product_id , IFNULL(second.average_price,0) as average_price 
from (select distinct product_id from Prices) as first
left join (
    select
    a.product_id , round(sum(a.price*b.units) / sum(b.units),2) as average_price
    from 
Prices as a
    join 
UnitsSold as b
    on a.product_id = b.product_id
where b.purchase_date between a.start_date and a.end_date
group by a.product_id 
) as second
on first.product_id = second.product_id