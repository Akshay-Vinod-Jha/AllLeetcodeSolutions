
select name
from (
    select
managerId , count(managerId) as count_is
from 
Employee
where managerId is not null
group by managerId 
) as lt
 join 
(
    select id , name from Employee

) as rt
on lt.managerId = rt.id

where count_is >= 5
