# Write your MySQL query statement below
select * from (
    select table1.name as name , table2.bonus as bonus
from 
    Employee as table1 left join Bonus as table2
on table1.empId = table2.empId
) as newtable where newtable.bonus < 1000 or newtable.bonus is null