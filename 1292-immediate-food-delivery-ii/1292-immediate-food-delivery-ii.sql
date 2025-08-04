WITH table1 AS (
    SELECT *,
           ROW_NUMBER() OVER (
               PARTITION BY customer_id
               ORDER BY order_date
           ) AS ofo
    FROM Delivery
),
table2 AS (
    SELECT * FROM table1 WHERE ofo = 1
),
table3 AS (
    SELECT *, DATEDIFF(order_date, customer_pref_delivery_date) AS diffis
    FROM table2
),
table4 AS (
    SELECT * FROM table3 WHERE diffis = 0
),table5 AS (
    SELECT 
    (SELECT COUNT(*) FROM table4) AS table4_count,
    (SELECT COUNT(*) FROM table2) AS table2_count
)
select round((table4_count*100)/(table2_count),2) as immediate_percentage from table5
