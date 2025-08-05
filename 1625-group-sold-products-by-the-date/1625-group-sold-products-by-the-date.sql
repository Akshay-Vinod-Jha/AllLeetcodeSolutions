SELECT 
    sell_date, 
    COUNT(*) AS num_sold, 
    GROUP_CONCAT(product ORDER BY product SEPARATOR ',') AS products
FROM (
    SELECT DISTINCT sell_date, product
    FROM (
        SELECT sell_date, product,
               ROW_NUMBER() OVER (PARTITION BY sell_date ORDER BY product) AS RANKIS
        FROM Activities
    ) AS DUMMY1
) AS DUMMY2
GROUP BY sell_date
ORDER BY sell_date;
