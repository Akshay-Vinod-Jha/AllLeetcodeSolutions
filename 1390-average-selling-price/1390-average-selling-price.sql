SELECT 
    product_id, 
    COALESCE(
        ROUND(SUM(units * price) / NULLIF(SUM(units), 0), 2),
        0
    ) AS average_price
FROM (
    SELECT 
        a.product_id, 
        b.units, 
        price
    FROM Prices AS a
    LEFT JOIN UnitsSold AS b
        ON a.product_id = b.product_id 
       AND b.purchase_date BETWEEN a.start_date AND a.end_date
) AS a
GROUP BY a.product_id;
