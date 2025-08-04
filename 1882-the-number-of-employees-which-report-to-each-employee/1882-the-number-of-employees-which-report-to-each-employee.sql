# Write your MySQL query statement below
WITH TABLE1 AS (
    SELECT reports_to , COUNT(*) AS reports_count , ROUND(AVG(age )) AS average_age   FROM Employees 
    WHERE reports_to IS NOT NULL
    GROUP BY reports_to 
)
SELECT TABLE1.reports_to AS employee_id , Employees.name ,TABLE1.reports_count , TABLE1.average_age  FROM TABLE1
LEFT JOIN
Employees 
ON TABLE1.reports_to = Employees.employee_id 
ORDER BY employee_id