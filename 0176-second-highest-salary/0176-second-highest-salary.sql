WITH table1 AS (
    SELECT salary, 
           DENSE_RANK() OVER (ORDER BY salary DESC) AS rankis
    FROM Employee
)
SELECT 
    CASE
        WHEN EXISTS (SELECT 1 FROM table1 WHERE rankis = 2) 
             THEN (SELECT salary FROM table1 WHERE rankis = 2 LIMIT 1)
        ELSE NULL
    END AS SecondHighestSalary;
