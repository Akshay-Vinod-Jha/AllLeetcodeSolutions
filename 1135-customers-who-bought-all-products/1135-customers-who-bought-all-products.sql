# Write your MySQL query statement below
WITH TABLE1 AS (
    SELECT customer_id ,product_key  FROM Customer 
GROUP BY customer_id ,product_key
),
TABLE2 AS (
    SELECT * FROM TABLE1 WHERE product_key IN (SELECT product_key FROM Product )
),
TABLE3 AS (
    SELECT customer_id FROM TABLE2 GROUP BY customer_id HAVING COUNT(*) = (SELECT DISTINCT COUNT(*) FROM Product )
)
SELECT * FROM TABLE3