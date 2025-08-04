WITH TABLE1 AS (
    SELECT * FROM Queue
),
TABLE2 AS (
    SELECT *,
       SUM(weight) OVER (
           ORDER BY turn
           ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW
       ) AS Total_Weight
    FROM TABLE1
)

SELECT person_name FROM TABLE2 WHERE Total_Weight <= 1000 
ORDER BY Total_Weight DESC LIMIT 1

