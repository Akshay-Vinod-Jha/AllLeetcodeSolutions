with table1 as (
    select country,
           concat(year(approvedtable.trans_date),'-',lpad(month(approvedtable.trans_date),2,'0')) as anotherPri,
           count(*) as approved_count,
           sum(amount) as approved_total_amount
    from (
        select * from Transactions where state = "approved"
    ) as approvedtable
    group by approvedtable.country, concat(year(approvedtable.trans_date),'-',lpad(month(approvedtable.trans_date),2,'0'))
),
table2 as (
    select country,
           concat(year(trans_date),'-',lpad(month(trans_date),2,'0')) as anotherPri,
           sum(amount) as trans_total_amount,
           count(*) as trans_count
    from Transactions
    group by country, concat(year(trans_date),'-',lpad(month(trans_date),2,'0')) 
)
select table2.anotherPri as month,
       table2.country as country,
       trans_count,
       IFNULL(approved_count,0) AS approved_count,
       trans_total_amount,
       IFNULL(approved_total_amount,0) AS approved_total_amount
from table1
right join table2
  on ( table1.country=table2.country or (table1.country is null and table2.country is null) )
 and table1.anotherPri = table2.anotherPri;
