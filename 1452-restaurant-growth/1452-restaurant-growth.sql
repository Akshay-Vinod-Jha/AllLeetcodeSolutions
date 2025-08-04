SELECT 
    ADDDATE(A, INTERVAL 6 DAY) AS visited_on,
    sum_amount AS amount,
    ROUND(sum_amount / days_count, 2) AS average_amount
FROM (
    SELECT 
        visited_on AS A, 
        (
            SELECT SUM(amount) 
            FROM Customer 
            WHERE visited_on BETWEEN A AND ADDDATE(A, INTERVAL 6 DAY)
        ) AS sum_amount,
        (
            SELECT COUNT(DISTINCT visited_on) 
            FROM Customer 
            WHERE visited_on BETWEEN A AND ADDDATE(A, INTERVAL 6 DAY)
        ) AS days_count
    FROM Customer
) AS DUMMY
WHERE ADDDATE(A, INTERVAL 6 DAY) IN (
    SELECT DISTINCT visited_on FROM Customer
) GROUP BY visited_on ;
