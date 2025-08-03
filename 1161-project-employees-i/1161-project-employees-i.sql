# Write your MySQL query statement below
select project_id , round((sum(experience_years)/count(*)),2) as average_years 
from 
    (
        select project_id , experience_years  
from  
    Project
    inner join 
    Employee
on Project.employee_id = Employee.employee_id
    ) as a
group by project_id



