# Write your MySQL query statement below
SELECT * 
FROM (
    SELECT id, SUM(num) AS num
    FROM (
        SELECT requester_id AS id, COUNT(*) AS num 
        FROM RequestAccepted 
        GROUP BY requester_id

        UNION ALL

        SELECT accepter_id AS id, COUNT(*) AS num 
        FROM RequestAccepted
        GROUP BY accepter_id
    ) AS table3
    GROUP BY id
) AS table4
ORDER BY num DESC
LIMIT 1;
