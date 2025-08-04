# Write your MySQL query statement below
WITH TABLE1 AS (
    SELECT * FROM Employees WHERE manager_id IS NOT NULL
),TABLE2 AS (
    SELECT DISTINCT employee_id FROM Employees 
),TABLE3 AS (
    SELECT * FROM TABLE1 WHERE manager_id NOT IN (SELECT employee_id FROM TABLE2)
)
SELECT employee_id  FROM TABLE3 WHERE salary < 30000 ORDER BY employee_id