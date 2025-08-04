# Write your MySQL query statement below
select Department.name as Department , Employee, Salary from (
        select departmentId , name  as Employee , salary as Salary   from (
            select id , name , salary , departmentId,
                dense_rank() over (partition by departmentId order by salary desc) as orderis
        from Employee 
        ) as table1 where orderis < 4
) as table2 
inner join 
Department 
on table2.departmentId=Department.id