# Write your MySQL query statement below
WITH TABLE1 AS (
    SELECT *,
    CASE
        WHEN income <20000 THEN "Low Salary"
        WHEN income between 20000 and 50000 THEN "Average Salary"
        ELSE "High Salary"
    END AS salary
FROM
    Accounts 
),TABLE2 AS (
    SELECT "High Salary" AS category
    UNION ALL 
    SELECT "Low Salary" AS category
    UNION ALL
    SELECT "Average Salary" AS category
),TABLE3 AS (
    SELECT salary AS category , COUNT(*) AS accounts_count 
    FROM TABLE1
    GROUP BY category
)

SELECT TABLE2.category , IFNULL(accounts_count,0) AS accounts_count 
FROM TABLE2
LEFT JOIN 
TABLE3
ON TABLE2.category = TABLE3.category
