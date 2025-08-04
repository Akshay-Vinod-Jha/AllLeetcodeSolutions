# Write your MySQL query statement below
WITH TABLE1 AS (
    SELECT DISTINCT product_id FROM Products 
),
TABLE2 AS (
    SELECT * FROM Products 
    WHERE change_date <= "2019-08-16"   
),
TABLE3 AS (
    SELECT *,
        DENSE_RANK() OVER (PARTITION BY product_id ORDER BY change_date DESC) AS RANKISIMP
        FROM TABLE2
)


SELECT TABLE1.product_id AS  product_id,IFNULL(LASTABLE.price,10) AS price
FROM 
    TABLE1
    LEFT JOIN
    (SELECT product_id ,new_price AS price  FROM TABLE3 WHERE RANKISIMP = 1) AS LASTABLE
    ON TABLE1.product_id = LASTABLE.product_id