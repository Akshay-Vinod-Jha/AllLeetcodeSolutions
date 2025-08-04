WITH TABLE1 AS (
    SELECT *,
           DENSE_RANK() OVER (PARTITION BY product_id ORDER BY year) AS rnk
    FROM Sales
)
SELECT product_id,
       year AS first_year,
       quantity,
       price
FROM TABLE1
WHERE rnk = 1;
