SELECT 
    a.query_name, 
    ROUND(Rquality / total, 2) AS quality, 
    ROUND((IFNULL(poor_count,0) / total)*100, 2) AS poor_query_percentage
FROM 
    (
        SELECT query_name, 
               SUM(rating / position) AS Rquality, 
               COUNT(*) AS total
        FROM Queries 
        GROUP BY query_name
    ) AS a
LEFT JOIN
    (
        SELECT query_name, 
               COUNT(*) AS poor_count
        FROM Queries 
        WHERE rating < 3 
        GROUP BY query_name
    ) AS b
ON a.query_name = b.query_name;
