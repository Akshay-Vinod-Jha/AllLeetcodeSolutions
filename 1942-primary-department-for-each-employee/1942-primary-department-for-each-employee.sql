# Write your MySQL query statement below
WITH TABLE1 AS (
    SELECT employee_id , department_id  FROM Employee 
    WHERE primary_flag = 'Y'
),
TABLE2 AS (
    SELECT employee_id,department_id FROM Employee WHERE employee_id NOT IN 
    (SELECT employee_id FROM TABLE1)
)

SELECT employee_id , department_id  FROM TABLE1 
UNION 
SELECT employee_id , department_id  FROM TABLE2