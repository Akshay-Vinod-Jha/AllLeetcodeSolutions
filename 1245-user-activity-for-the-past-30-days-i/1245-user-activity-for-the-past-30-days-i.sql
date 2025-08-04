# Write your MySQL query statement below
WITH TABLE1 AS (
    SELECT * FROM Activity WHERE activity_date BETWEEN SUBDATE("2019-07-27", INTERVAL 29 DAY) AND "2019-07-27" 
),
TABLE2 AS (
    SELECT user_id ,activity_date FROM TABLE1 GROUP BY user_id,activity_date
),
TABLE3 AS (
    SELECT activity_date AS day , COUNT(*) AS active_users FROM TABLE2 GROUP BY activity_date 
)
SELECT * FROM TABLE3 ORDER BY day 